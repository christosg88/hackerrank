#include <iostream>
#include <string>

size_t count_char(std::string str, char ch);

int main()
{
	std::ios::sync_with_stdio(false);

	// the basic string, that will be repeated infinite times
	std::string str;
	std::cin >> str;
	// the number of the n first characters from the infinite string
	size_t n_first;
	std::cin >> n_first;
	// the length of the string
	size_t length = str.size();

	// output the number of 'a's in the n first characters of the infinite string
	std::cout << (count_char(str, 'a') * (n_first / length)) + count_char(str.substr(0, n_first % length), 'a');

	return 0;
}

/// <summary>
/// Counts the frequency that ch appears in str.
/// </summary>
/// <param name="str">The string to be searched.</param>
/// <param name="ch">The character to be found in str.</param>
/// <returns>The frequency of ch in str</returns>
size_t count_char(std::string str, char ch)
{
	size_t count = 0;
	for (auto it = str.begin(); it != str.end(); ++it)
		if (*it == ch)
			count++;
	return count;
}