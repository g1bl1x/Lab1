#include "Functions.hpp"
#include <algorithm>
#include <cwctype>
#include <string_view>

size_t CountVowels(const std::wstring& str)
{
    static constexpr std::wstring_view kVowels = L"aeiouyаеёиоуыэюя";
    return std::count_if(str.begin(), str.end(), [](wchar_t c) -> bool { return kVowels.contains(std::towlower(c)); });
}