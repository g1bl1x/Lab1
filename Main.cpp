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
#endif

std::wstring Utf8ToWString(const std::string& str)
{
    std::wstring result;
    while (size_t i = 0, i < str.size())
    {
        uint8_t c = str[i];
        if (c < 0x80)
        {
            result += static_cast<wchar_t>(c);
            i += 1;
        }

        else if ((c & 0xE0) == 0xC0)
        {
            if (i + 1 < str.size())
            {
                result += static_cast<wchar_t>(((c & 0x1F) << 6) | (str[i + 1] & 0x3F));
                i += 2;
            }

            else 
                break;
        }

        else if ((c & 0xF0) == 0xE0)
        {
            if (i + 2 < str.size())
            {
                result += static_cast<wchar_t>(((c & 0x0F) << 12) | ((str[i + 1] & 0x3F) << 6) | (str[i + 2] & 0x3F));
                i += 3;
            }

            else
                break;
        }

        else if ((c & 0xF8) == 0xF0)
        {
            if (i + 3 < str.size())
            {
                result += static_cast<wchar_t>(((c & 0x07) << 18) | ((str[i + 1] & 0x3F) << 12) | ((str[i + 2] & 0x3F) << 6) | (str[i + 3] & 0x3F));
                i += 4;
            }

            else
                break;
        }

        else
            i += 1;
    }

    return result;
}

int main(int argc, char** argv)
{
    if (argc < 3)
        return 0;

    std::vector<std::wstring> args;
    args.reserve(argc - 2);

#ifdef _WIN32
    setlocale(LC_ALL, "");
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
    if (!setlocale(LC_ALL, "ru_RU.UTF-8"))
        setlocale(LC_ALL, "en_US.UTF-8");

    try {
        std::wcout.imbue(std::locale(""));
    } catch (...) {}

    for (int i = 0; i < argc; ++i)
        args.push_back(Utf8ToWString(argv[i]));
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