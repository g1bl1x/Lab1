#include "Functions.hpp"

void StripSpecialCharacters(std::string& str)
{
	std::erase_if(str, [](char c) -> bool { return std::ispunct(c) || std::iscntrl(c); });
}