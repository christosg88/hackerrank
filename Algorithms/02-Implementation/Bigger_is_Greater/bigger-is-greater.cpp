#include <iostream>
#include <string>
#include <algorithm>

bool next_lexicographic_permutation(std::string &str);

int main()
{
	std::ios::sync_with_stdio(false);

	size_t testcases;
	std::cin >> testcases;

	for (size_t testcase = 0; testcase < testcases; testcase++)
	{
		std::string str;
		std::cin >> str;

		if (next_lexicographic_permutation(str))
			std::cout << str << '\n';
		else
			std::cout << "no answer\n";
	}

	return 0;
}

/// <summary>
/// Finds the next lexicographic permutation of str.
/// (my implementation of the algorithm described here:
/// https://www.nayuki.io/page/next-lexicographical-permutation-algorithm).
/// </summary>
/// <param name="str">The string.</param>
/// <returns>Returns true if there is a next permutation else false</returns>
bool next_lexicographic_permutation(std::string &str)
{
	size_t length = str.size();

	// 1. find the largest index k so that str[k] < str[k + 1]
	int k = -1;
	for (size_t i = 0; i < length - 1; ++i)
	{
		if (str[i] < str[i + 1])
			k = i;
	}

	// if k == -1, then there is no greater lexicographic permutation
	if (k == -1)
		return false;

	// 2. find the largest index l greater than k such that str[k] < str[l]
	int l;
	for (size_t i = k + 1; i < length; ++i)
	{
		if (str[k] < str[i])
			l = i;
	}

	// 3. swap the value of str[k] with that of str[l]
	std::swap(str[k], str[l]);

	// 4. reverse the sequence from str[k+1] up to and including the final
	// element
	std::reverse(str.begin() + k + 1, str.end());

	return true;
}
