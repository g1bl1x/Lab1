#include "Functions.hpp"
#include <algorithm>
#include <string_view>

size_t CountVowels(const std::string& str)
{
	static constexpr std::string_view kVowels = "aeiouy";
	return std::count_if(str.begin(), str.end(), [](char c) -> bool { return kVowels.contains(std::tolower(c)); });
}