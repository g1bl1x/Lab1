#include "Functions.hpp"
#include <print>
#include <vector>

int main(int argc, char** argv)
{
	if (argc < 2)
		return 0;

	std::vector<std::string> vec(argv + 1, argv + argc);
	for (auto& str : vec)
	{
		std::println("palindrome: {}", IsPalindrome(str));
		std::println("vowels: {}", CountVowels(str));

		ConvertCase(str, Case::Upper);
		std::println("uppercase: {}", str);

		ConvertCase(str, Case::Lower);
		std::println("lowercase: {}", str);

		StripSpecialCharacters(str);
		std::println("stripped: {}\n", str);
	}
}