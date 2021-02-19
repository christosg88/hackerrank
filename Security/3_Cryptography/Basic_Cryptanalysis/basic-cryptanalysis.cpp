#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <algorithm>
#include <map>
#include <vector>

bool is_isomorphic(const std::string &s1, const std::string &s2);
bool is_partial_match(const std::string &cypher, const std::string &plain, const std::map<char, char> &char_map);
void get_char_mapping(std::set<std::string> &cypher_set, std::set<std::string> &plain_set, std::map<char, char> &char_map);


int main()
{
	std::ios::sync_with_stdio(false);

	// the dictionary file
	std::ifstream infile("dictionary.lst");

	// if there was a problem opening the file, return 1
	if (!infile)
		return 1;

	// the set to hold the dictionary words
	std::set<std::string> dict;

	// read and store the dictionary
	std::string str;
	while (infile >> str)
	{
		std::transform(str.begin(), str.end(), str.begin(), ::tolower);
		dict.insert(str);
	}

	// the vector to hold the cypher-text words
	std::vector<std::string> cypher_vector;

	// read and store the cypher-text
	while (std::cin >> str)
	{
		std::transform(str.begin(), str.end(), str.begin(), ::tolower);
		cypher_vector.push_back(str);
	}

	// the set to hold the same words
	std::set<std::string> cypher_set(cypher_vector.begin(), cypher_vector.end());

	// a mapping from cypher-text characters to plain-text
	std::map<char, char> char_map;

	get_char_mapping(cypher_set, dict, char_map);

	// having mapped all the characters that we could, translate the cypher-text
	for (auto it_cypher = cypher_vector.begin(); it_cypher != cypher_vector.end(); ++it_cypher)
	{
		for (auto it_char = (*it_cypher).begin(); it_char != (*it_cypher).end(); ++it_char)
		{
			std::cout << char_map[*it_char];
		}
		std::cout << ' ';
	}

	return 0;
}

/// <summary>
/// Determines whether s1 and s2 are isomorphic.
/// e.g.	xyy, azz -> true
///			paper, title -> true
///			egg, fox -> false
/// </summary>
/// <param name="s1">The s1.</param>
/// <param name="s2">The s2.</param>
/// <returns>
///   <c>true</c> if s1 and s2 are isomorphic; otherwise, <c>false</c>.
/// </returns>
bool is_isomorphic(const std::string &s1, const std::string &s2)
{
	// if their length are different return false
	if (s1.length() != s2.length())
		return false;

	std::map<char, char> char_map1, char_map2;

	for (auto it1 = s1.begin(), it2 = s2.begin(); it1 != s1.end(); ++it1, ++it2)
	{
		auto search1 = char_map1.find(*it1);
		auto search2 = char_map2.find(*it2);

		// check if they are both at end or both not at end
		if ((search1 == char_map1.end()) == (search2 == char_map2.end()))
		{
			// if they are both at end, add new mapping
			if (search1 == char_map1.end())
			{
				char_map1[*it1] = *it2;
				char_map2[*it2] = *it1;
			}
			// if there is a different mapping, return false
			else if (search1->second != search2->first)
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}

	return true;
}

/// <summary>
/// Determines whether the cypher partially matches plain using the char_map.
/// </summary>
/// <param name="cypher">The cypher string.</param>
/// <param name="plain">The plain string.</param>
/// <param name="char_map">The character map.</param>
/// <returns>
///   <c>true</c> if cypher partially matches plain using the char_map; otherwise, <c>false</c>.
/// </returns>
bool is_partial_match(const std::string &cypher, const std::string &plain, const std::map<char, char> &char_map)
{
	for (size_t i = 0, length = cypher.size(); i < length; i++)
	{
		auto search = char_map.find(cypher[i]);
		if (search != char_map.end() && search->second != plain[i])
			return false;
	}

	return true;
}

/// <summary>
/// Updates the character mapping from the cypher_set to the plain_set. Each
/// character is mapped always to the same other character.
/// </summary>
/// <param name="cypher_set">The cypher set.</param>
/// <param name="plain_set">The plain set.</param>
/// <param name="char_map">The character map.</param>
void get_char_mapping(std::set<std::string> &cypher_set, std::set<std::string> &plain_set, std::map<char, char> &char_map)
{
	bool added_mapping = true;

	// while we have added at least one new mapping
	while (added_mapping)
	{
		added_mapping = false;
		// for every string in the cypher set
		for (const std::string cypher : cypher_set)
		{
			std::string isomorph;
			size_t count_isomorph = 0;
			// try to find an isomorphic string in the plain_set, that is also
			// a partial match for the current char_map
			for (const std::string plain : plain_set)
			{
				if (is_isomorphic(cypher, plain) && is_partial_match(cypher, plain, char_map))
				{
					count_isomorph++;
					// if we found more than one isomorphic we can't use them
					if (count_isomorph > 1)
						break;
					isomorph = plain;
				}
			}

			// we found only one match, so we can map the characters
			if (count_isomorph == 1)
			{
				for (size_t i = 0, length = cypher.length(); i < length; i++)
					char_map[cypher[i]] = isomorph[i];
				cypher_set.erase(cypher);
				plain_set.erase(isomorph);
				added_mapping = true;
			}
		}
	}
}