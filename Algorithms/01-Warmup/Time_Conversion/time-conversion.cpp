#include <iostream>
#include <string>
#include <regex>
#include <iomanip>

int main()
{
	std::ios::sync_with_stdio(false);

	std::string str;
	std::cin >> str;

	std::smatch m;
	std::regex re("(\\d{2}):(\\d{2}):(\\d{2})(AM|PM)");

	std::regex_match(str, m, re);

	int hours = stoi(m.str(1));
	int minutes = stoi(m.str(2));
	int seconds = stoi(m.str(3));
	std::string am_pm = m.str(4);

	if (am_pm.compare("PM") == 0 && hours != 12)
		hours += 12;
	else if (am_pm.compare("AM") == 0 && hours == 12)
		hours -= 12;

	std::cout << std::setfill('0') << std::setw(2) << hours << ':';
	std::cout << std::setfill('0') << std::setw(2) << minutes << ':';
	std::cout << std::setfill('0') << std::setw(2) << seconds << '\n';

	return 0;
}