#include "Functions.hpp"
#include <cwctype>

void ConvertCase(std::wstring& str, Case reg)
{
    for (wchar_t& c : str)
    {
        if (reg == Case::Upper)
            c = std::towupper(c);

        else
            c = std::towlower(c);
    }
}