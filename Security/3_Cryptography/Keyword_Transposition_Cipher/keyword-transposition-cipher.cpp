#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

/*
	If key is SECRET, we remove the duplicates getting SECRT.
	Then we put the leftover alphabet beneath these letters getting
		SECRT
		ABDFG
		HIJKL
		MNOPQ
		UVWXY
		Z
	Then we get the columns in alphabetical ascending order and put them back to back
	CDJOW EBINV RFKPX SAHMUZ TGLQY	(cypher alphabet)
	ABCDE FGHIJ KLMNO PQRSTU VWXYZ	(original alphabet)
*/
int main()
{
	std::ios::sync_with_stdio(false);

	size_t testcases;
	std::cin >> testcases;

	// for each testcase
	for (size_t test = 0; test < testcases; test++)
	{
		// read the key and the cypher text
		std::string key, cyphertext;
		std::cin >> key;
		std::cin.ignore(1);	// ignore the new line character left
		std::getline(std::cin, cyphertext);

		// remove duplicates from the key
		for (auto it = key.begin(); it < key.end() - 1; ++it)
		{
			for (auto it2 = it + 1; it2 < key.end();)
			{
				if (*it == *it2)
					it2 = key.erase(it2);
				else
					it2++;
			}
		}

		std::string sorted_key = key;
		std::sort(sorted_key.begin(), sorted_key.end());

		size_t key_len = key.length();

		std::vector<char> alphabet = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };

		// remove the letters in key from the alphabet
		size_t counter = 0;
		for (char c : sorted_key)
		{
			alphabet.erase(alphabet.begin() + int(c - 'A') - counter);
			counter++;
		}

		// put the key in front of the alphabet
		alphabet.insert(alphabet.begin(), key.begin(), key.end());

		// create the columns of the new alphabet
		std::vector<std::vector<char>> columns;
		for (size_t i = 0; i < key_len; i++)
		{
			std::vector<char> tmp;
			size_t pos = i;
			while (pos < 26)
			{
				tmp.push_back(alphabet[pos]);
				pos += key_len;
			}
			columns.push_back(tmp);
		}

		// custom comparer for sort
		struct
		{
			bool operator()(std::vector<char> &a, std::vector<char> &b)
			{
				return a[0] < b[0];
			}
		} custom;

		// sort the columns based on their first letter
		std::sort(columns.begin(), columns.end(), custom);

		// create the new alphabet
		size_t count = 0;
		std::map<char, char> new_alphabet;
		for (auto v : columns)
		{
			for (char c : v)
			{
				new_alphabet[c] = 'A' + count;
				count++;
			}
		}

		// print the decrypted message
		for (char c : cyphertext)
		{
			if (c == ' ')
				std::cout << ' ';
			else
				std::cout << new_alphabet[c];
		}

		std::cout << '\n';
	}

	return 0;
}