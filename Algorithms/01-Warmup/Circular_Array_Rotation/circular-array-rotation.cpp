#include <iostream>
#include <vector>

int get_rotated(std::vector<int> &nums, int index, int start, int length);

int main()
{
	std::ios::sync_with_stdio(false);

	size_t length, rotations, queries;
	std::cin >> length >> rotations >> queries;

	// read the number in the vector
	std::vector<int> nums(length);
	for (size_t i = 0; i < length; i++)
		std::cin >> nums[i];

	// the rotations should be modulo the length of the list, since for a list
	// of 3 numbers, 3 rotations and 0 rotations are the same.
	rotations = rotations % length;

	// the new start in the array
	int start = length - rotations;

	for (int i = 0; i < queries; ++i)
	{
		int query;
		std::cin >> query;
		std::cout << get_rotated(nums, query, start, length) << '\n';
	}

	return 0;
}

int get_rotated(std::vector<int> &nums, int index, int start, int length)
{
	return nums[(start + index) % length];
}