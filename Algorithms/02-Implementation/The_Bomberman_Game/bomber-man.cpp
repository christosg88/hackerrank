#include <iostream>
#include <vector>
#include <memory>

class BombGrid
{
public:
	BombGrid(size_t rows, size_t cols)
	{
		this->rows = rows;
		this->cols = cols;
		this->length = rows * cols;
		this->grid = new std::vector<char>(length);
	}

	~BombGrid()
	{
		delete grid;
	}

	std::shared_ptr<BombGrid> get_full_grid();
	std::shared_ptr<BombGrid> get_exploded_grid();

	friend std::ostream &operator<<(std::ostream &stream, BombGrid &bomb_grid);
	friend std::istream &operator>>(std::istream &stream, BombGrid &bomb_grid);

private:
	size_t rows, cols, length;
	std::vector<char> *grid;
};

std::shared_ptr<BombGrid> BombGrid::get_full_grid()
{
	std::shared_ptr<BombGrid> after(new BombGrid(rows, cols));
	for (size_t i = 0; i < length; i++)
		after->grid->at(i) = 'O';

	return after;
}

std::shared_ptr<BombGrid> BombGrid::get_exploded_grid()
{
	std::shared_ptr<BombGrid> after = get_full_grid();
	for (size_t i = 0; i < length; i++)
	{
		if (grid->at(i) == 'O')
		{
			// center
			after->grid->at(i) = '.';
			// up
			if (i >= after->cols)
				after->grid->at(i - after->cols) = '.';
			// down
			if (i + after->cols < length)
				after->grid->at(i + after->cols) = '.';
			// left
			if (i % after->cols != 0)
				after->grid->at(i - 1) = '.';
			// right
			if (i % after->cols != after->cols - 1)
				after->grid->at(i + 1) = '.';
		}
	}

	return after;
}

std::ostream &operator<<(std::ostream &stream, BombGrid &bomb_grid)
{
	for (size_t i = 0; i < bomb_grid.length; i++)
	{
		stream << bomb_grid.grid->at(i);
		if (i % bomb_grid.cols == bomb_grid.cols - 1)
			stream << '\n';
	}

	return stream;
}

std::istream &operator>>(std::istream &stream, BombGrid &bomb_grid)
{
	for (size_t i = 0; i < bomb_grid.length; i++)
		stream >> bomb_grid.grid->at(i);
	
	return stream;
}

int main()
{

	std::ios::sync_with_stdio(false);

	size_t rows, cols, sec;
	std::cin >> rows >> cols >> sec;

	BombGrid grid(rows, cols);

	std::cin >> grid;

	if (sec <= 1)							// 0, 1
		std::cout << grid;
	else if (sec % 2 == 0)					// 2, 4, 6, 8, 10, ...
		std::cout << *(grid.get_full_grid());
	else if ((sec - 3) % 4 == 0)			// 3, 7, 11, 15, 19, 23, ...
		std::cout << *(grid.get_exploded_grid());
	else									// 5, 9, 13, 17, 21, 25, ...
		std::cout << *(grid.get_exploded_grid()->get_exploded_grid());

	return 0;
}