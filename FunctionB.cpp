#include "Functions.hpp"

void ConvertCase(std::string& str, Case reg)
{
    for (char& c : str)
    {
        if (reg == Case::Upper)
            c = toupper(c);

        else
            c = tolower(c);
    }
}