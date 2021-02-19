#include <iostream>
#include <string>

int main()
{
	std::ios_base::sync_with_stdio(false);

	std::string plaintext;
	std::cin >> plaintext;

	int shift;
	std::cin >> shift;
	shift %= 10;

	std::string cyphertext(plaintext, 0);
	for (size_t i = 0, length = cyphertext.length(); i < length; i++)
		cyphertext[i] = (((int)(cyphertext[i] - '0') + shift) % 10) + '0';

	std::cout << cyphertext << '\n';

	return 0;
}