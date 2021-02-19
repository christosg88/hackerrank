#include <iostream>

int main()
{
	std::ios::sync_with_stdio(false);

	size_t testcases;
	std::cin >> testcases;

	for (size_t testcase = 0; testcase < testcases; testcase++)
	{
		size_t students, threshold;
		std::cin >> students >> threshold;

		// count the number of students that arrived on time
		int count_on_time = 0;
		for (size_t student = 0; student < students; student++)
		{
			int arrival;
			std::cin >> arrival;
			if (arrival <= 0)
				count_on_time++;
		}

		// print if the class will be canceled
		if (count_on_time >= threshold)
			std::cout << "NO\n";
		else
			std::cout << "YES\n";
	}

	return 0;
}