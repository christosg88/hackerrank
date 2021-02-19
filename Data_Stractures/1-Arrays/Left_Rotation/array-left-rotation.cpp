#include <iostream>

int main(void)
{
	int count, left_rotations;
	std::cin >> count >> left_rotations;

	left_rotations %= count;

	int *nums = new int[count];

	for (size_t i = 0; i < count; i++)
		std::cin >> nums[i];

	for (size_t i = 0; i < count; i++)
		std::cout << nums[(i + left_rotations) % count] << ' ';

	return 0;
}