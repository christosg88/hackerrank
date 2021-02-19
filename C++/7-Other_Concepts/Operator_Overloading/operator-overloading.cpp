#include <iostream>
#include <vector>

class Matrix
{
    int get_num_rows();
    int get_num_cols();
public:
    std::vector<std::vector<int>> a;
    Matrix operator+(Matrix second);
};

int Matrix::get_num_rows()
{
    return this->a.size();
}

int Matrix::get_num_cols()
{
    return this->a[0].size();
}

Matrix Matrix::operator+(Matrix second)
{
    Matrix result;

    int num_rows = this->get_num_rows();
    int num_cols = this->get_num_cols();

    for (register int i = 0; i < num_rows; ++i)
    {
        std::vector<int> tmp(num_cols);
        for (register int j = 0; j < num_cols; ++j)
        {
            tmp[j] = this->a[i][j] + second.a[i][j];
        }

        result.a.push_back(tmp);
    }

    return result;
}

int main()
{
    int cases;
    std::cin >> cases;

    for (int k = 0; k < cases; ++k)
    {
        Matrix x, y, result;

        int num_of_rows, num_of_columns;

        std::cin >> num_of_rows >> num_of_columns;

        // read the first matrix
        for (register int i = 0; i < num_of_rows; ++i)
        {
            std::vector<int> b;
            for (register int j = 0; j < num_of_columns; ++j)
            {
                int num;
                std::cin >> num;
                b.push_back(num);
            }

            x.a.push_back(b);
        }

        // read the second matrix
        for (register int i = 0; i < num_of_rows; ++i)
        {
            std::vector<int> b;
            for (register int j = 0; j < num_of_columns; ++j)
            {
                int num;
                std::cin >> num;
                b.push_back(num);
            }

            y.a.push_back(b);
        }

        // find their sum
        result = x + y;

        // print the resulting matrix
        for (register int i = 0; i < num_of_rows; ++i)
        {
            for (register int j = 0; j < num_of_columns; ++j)
            {
                std::cout << result.a[i][j] << ' ';
            }
            std::cout << '\n';
        }
    }

    return 0;
}
