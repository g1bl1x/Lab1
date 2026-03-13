#include "Functions.hpp"
#include <algorithm>
#include <cwctype>

void StripSpecialCharacters(std::wstring& str)
{
	std::erase_if(str, [](wchar_t c) -> bool { return std::iswpunct(c) || std::iswcntrl(c) && c != L' '; });
}