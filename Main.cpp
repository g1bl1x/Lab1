#include "Functions.hpp"
#include <iostream>
#include <vector>
#include <string>

#ifdef _WIN32
#include <windows.h>
#include <shellapi.h>
#include <io.h>
#include <fcntl.h>
#pragma comment(lib, "shell32.lib")
#else
#include <locale>
#include <codecvt>
#endif

int main(int argc, char** argv)
{
    if (argc < 3)
        return 0;

    std::setlocale(LC_ALL, "");

    std::vector<std::wstring> args;
    args.reserve(argc - 2);

#ifdef _WIN32
    _setmode(_fileno(stdout), _O_U16TEXT);

    int wargc;
    LPWSTR* wargv = CommandLineToArgvW(GetCommandLineW(), &wargc);
    if (wargv)
    {
        for (int i = 0; i < wargc; ++i)
            args.push_back(wargv[i]);
        LocalFree(wargv);
    }
#else
    std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
    for (int i = 0; i < argc; ++i)
    {
        try {
            args.push_back(converter.from_bytes(argv[i]));
        } catch (const std::range_error&) {
            args.push_back(L"");
        }
    }
#endif
    std::wstring mode = args[1];

    for (size_t i = 2; i < args.size(); ++i)
    {
        std::wstring wstr = args[i];
        std::wcout << L"original: " << wstr << L"\n";

        if (mode == L"-a" || mode == L"-all")
            std::wcout << L"vowels: " << CountVowels(wstr) << L"\n";

        if (mode == L"-b" || mode == L"-all")
        {
            std::wstring temp = wstr;
            ConvertCase(temp, Case::Upper);
            std::wcout << L"uppercase: " << temp << L"\n";
            ConvertCase(temp, Case::Lower);
            std::wcout << L"lowercase: " << temp << L"\n";
        }

        if (mode == L"-c" || mode == L"-all")
        {
            std::wstring temp = wstr;
            StripSpecialCharacters(temp);
            std::wcout << L"stripped: " << temp << L"\n";
        }

        if (mode == L"-d" || mode == L"-all")
            std::wcout << L"palindrome: " << (IsPalindrome(wstr) ? L"true" : L"false") << L"\n";

        std::wcout << L"\n";
    }
}

/*
# 1. Тест на гласные (Кириллица + Латиница + Пустая строка)
-a "Очередь" "Queue" ""

# 2. Тест на регистр (Смешанный ввод)
-b "Съешь ещё этих МЯГКИХ французских булок" "C++23 Standard"

# 3. Тест на спецсимволы (Знаки препинания, табы, символы)
-c "Привет, мир! (Hello... world?)" "Price: $100 & Exit#1"

# 4. Тест на палиндромы (Успех и Провал)
-d "шалаш" "потоп" "level" "not_a_palindrome" "Racecar"

# 5. Полный охват (Сразу всё)
-all "!аргентинаманитнегра!" "123-ABC-321" "!!!Спец-Тест!!!"
*/