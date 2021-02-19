#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

int main()
{
	std::ios::sync_with_stdio(false);

	// the length of the set
	size_t length;
	std::cin >> length;

	// the modulo that the sums should be non-divisible
	int modulo;
	std::cin >> modulo;

	// the set of the numbers (we use vector for faster insertion instead of set)
	std::vector<int> nums(length);
	for (size_t i = 0; i < length; i++)
	{
		int num;
		std::cin >> num;
		nums[i] = num;
	}

	// The sum of two numbers A and B is divisible by K,
	// if A is divisible by K and B is divisible by K
	// or (A % K) + (B % K) is equal to K
	// 
	// Example: modulo == 5
	// if we include a number with remainder 1
	// we can't include a number with remainder 4,
	// or else their sum would give a divisible by 5.
	// So we choose the set with the most numbers
	// from the set with remainder 1 and the set with remainder 4

	// find all possible remainders and their frequencies
	std::map<int, int> remainders;
	for (auto it = nums.begin(); it != nums.end(); ++it)
	{
		// if the remainder already exists, increment by one
		// else initialize to 1
		remainders[*it % modulo] += 1;
	}

	// size of the non-divisible-subset
	int count = 0;

	// assemble the largest subset
	for (auto it = remainders.begin(); it != remainders.end(); ++it)
	{
		// if we have a number divisible by modulo, we can insert it in the set,
		// but no other number divisible by modulo can be inserted
		if (it->first == 0)
		{
			count++;
			continue;
		}

		int max = it->second;
		std::map<int, int>::iterator search = remainders.find(modulo - it->first);
		if (search != remainders.end() && search->first != it->first)
		{
			max = std::max(max, search->second);
			remainders.erase(search);
		}

		count += max;
	}

	// if the modulo is even, its half can be included at most once
	if (modulo % 2 == 0 && remainders.count(modulo / 2) == 1)
	{
		// subtract the already included
		count -= remainders[modulo / 2];
		// add just the one
		count += 1;
	}

	std::cout << count << '\n';

	return 0;
}