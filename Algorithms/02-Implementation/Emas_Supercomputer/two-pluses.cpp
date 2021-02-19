#include <iostream>
#include <vector>
#include <stdexcept>

#define uint unsigned int

/// <summary>
/// A std::vector that is being used with array indexing.
/// </summary>
template<class T> class VectorArray
{
public:
	VectorArray(size_t rows, size_t cols) : rows(rows), cols(cols), length(rows * cols)
	{
		vector_array = new std::vector<T>(length);
	}

	~VectorArray()
	{
		delete vector_array;
	}

	T &at(uint row, uint col)
	{
		if (row < 0 || col < 0 || row >= rows || col >= cols)
			throw std::out_of_range("row or/and column out of range.");

		return vector_array->at(row * cols + col);
	}

private:
	std::vector<T> *vector_array;
	size_t rows, cols, length;
};

/// <summary>
/// A class representing a plus sign, constructed by "G" blocks.
/// </summary>
class Plus
{
public:
	Plus(uint x, uint y, uint length) : x(x), y(y), length(length)
	{}

	uint get_length()
	{
		return length;
	}

	uint get_x()
	{
		return x;
	}

	uint get_y()
	{
		return y;
	}

private:
	uint length;
	uint x, y;
};

bool are_intersecting(uint a_x, uint a_y, uint b_x, uint b_y, uint a_len, uint b_len);
size_t get_max_plus_length(VectorArray<char> &grid, uint x, uint y);
size_t get_max_area_without_intersecting(Plus &a, Plus &b);

int main()
{
	std::ios::sync_with_stdio(false);

	uint rows, cols;
	std::cin >> rows >> cols;

	VectorArray<char> grid = VectorArray<char>(rows, cols);

	for (size_t i = 0; i < rows; i++)
		for (size_t j = 0; j < cols; j++)
			std::cin >> grid.at(i, j);

	std::vector<Plus> pluses;

	for (size_t i = 0; i < rows; i++)
		for (size_t j = 0; j < cols; j++)
			if (grid.at(i, j) == 'G')
				pluses.push_back(Plus(i, j, get_max_plus_length(grid, i, j)));

	size_t max_area = 0;
	for (auto it1 = pluses.begin(); it1 != pluses.end() - 1; ++it1)
	{
		for (auto it2 = it1 + 1; it2 != pluses.end(); ++it2)
		{
			size_t area = get_max_area_without_intersecting(*it1, *it2);
			if (area > max_area)
				max_area = area;
		}
	}

	std::cout << max_area << '\n';

	return 0;
}

/// <summary>
/// Checks if two Pluses are intersecting.
/// </summary>
/// <param name="a_x">The x coordinate of a.</param>
/// <param name="a_y">The y coordinate of a.</param>
/// <param name="b_x">The x coordinate of b.</param>
/// <param name="b_y">The y coordinate of b.</param>
/// <param name="a_len">The length of a.</param>
/// <param name="b_len">The length of b.</param>
/// <returns>true if they are intersecting, else false.</returns>
bool are_intersecting(uint a_x, uint a_y, uint b_x, uint b_y, uint a_len, uint b_len)
{
	size_t max_len = a_len > b_len ? a_len : b_len;
	size_t min_len = a_len + b_len - max_len;

	size_t dx = a_x > b_x ? a_x - b_x : b_x - a_x;
	size_t dy = a_y > b_y ? a_y - b_y : b_y - a_y;

	if (dx == 0)
		return dy < a_len + b_len - 1;
	else if (dy == 0)
		return dx < a_len + b_len - 1;
	else if (dx >= max_len || dy >= max_len)
		return false;
	else
		return (dx < min_len) || (dy < min_len);
}

/// <summary>
/// Gets the maximum length of a Plus in the grid.
/// </summary>
/// <param name="grid">The grid.</param>
/// <param name="x">The x coordinate of the Plus.</param>
/// <param name="y">The y coordinate of the Plus.</param>
/// <returns>The maximum length of the Plus.</returns>
size_t get_max_plus_length(VectorArray<char> &grid, uint x, uint y)
{
	size_t length = 1;

	try
	{
		while (grid.at(x - length, y) == 'G' && grid.at(x + length, y) == 'G' &&
			grid.at(x, y - length) == 'G' && grid.at(x, y + length) == 'G')
		{
			length++;
		}
	}
	catch (std::out_of_range &oor)
	{
	}

	return length;
}

/// <summary>
/// Gets the maximum area between the two Pluses without intersecting.
/// </summary>
/// <param name="a">The a Plus.</param>
/// <param name="b">The b Plus.</param>
/// <returns>The maximum area between a and b without intesecting.</returns>
size_t get_max_area_without_intersecting(Plus &a, Plus &b)
{
	uint a_len = a.get_length(), b_len = b.get_length();
	while (a_len > 1 && are_intersecting(a.get_x(), a.get_y(), b.get_x(), b.get_y(), a_len, b_len))
	{
		a_len--;
	}

	size_t area1 = ((a_len - 1) * 4 + 1) * ((b_len - 1) * 4 + 1);

	a_len = a.get_length();
	while (b_len > 1 && are_intersecting(a.get_x(), a.get_y(), b.get_x(), b.get_y(), a_len, b_len))
	{
		b_len--;
	}

	size_t area2 = ((a_len - 1) * 4 + 1) * ((b_len - 1) * 4 + 1);

	if (area1 > area2)
		return area1;
	else
		return area2;
}