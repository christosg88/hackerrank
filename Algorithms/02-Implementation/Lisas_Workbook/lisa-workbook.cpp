#include <iostream>

int main()
{
	std::ios::sync_with_stdio(false);

	// the number of chapters in the book
	size_t num_chapters;
	std::cin >> num_chapters;

	// the number of problems per page
	size_t problems_per_page;
	std::cin >> problems_per_page;

	size_t count_special = 0;
	size_t current_page = 0;
	for (size_t chap = 0; chap < num_chapters; chap++)
	{
		// the number of problems in this chapter
		size_t num_problems;
		std::cin >> num_problems;

		for (size_t problem = 1; problem <= num_problems; problem++)
		{
			if (problem % problems_per_page == 1 || problems_per_page == 1)
				current_page++;

			if (problem == current_page)
				count_special++;
		}
	}

	std::cout << count_special << '\n';

	return 0;
}