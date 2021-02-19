#include <iostream>
#include <fstream>

enum crossing {
    BOTTOM,
    TOP,
    LEFT,
    RIGHT,
    BOTTOM_LEFT,
    BOTTOM_RIGHT,
    TOP_LEFT,
    TOP_RIGHT,
    NONE
};

class Point {
public:
    int row, col;

    Point(int row, int col) : row(row), col(col) {
    };

    friend std::ostream &operator<<(std::ostream &os, const Point &point) {
        os << "row: " << point.row << " col: " << point.col << "\n";
        return os;
    }
};

int getChessDistance(Point &a, Point &b) {
    return std::max(std::abs(a.row - b.row), std::abs(a.col - b.col)) - 1;
}

crossing checkCrossing(const Point &a, const Point &b) {
    int row_diff = b.row - a.row;
    int col_diff = b.col - a.col;

    if (row_diff == 0) {
        if (col_diff == 0) {
            return NONE;
        }
        else if (col_diff > 0) {
            return RIGHT;
        }
        else {
            return LEFT;
        }
    }
    else if (row_diff > 0) {
        if (col_diff == 0) {
            return TOP;
        }
        else if (col_diff > 0 && row_diff == col_diff) {
            return TOP_RIGHT;
        }
        else if (col_diff < 0 && row_diff == -col_diff) {
            return TOP_LEFT;
        }
        else {
            return NONE;
        }
    }
    else {
        if (col_diff == 0) {
            return BOTTOM;
        }
        else if (col_diff > 0 && row_diff == -col_diff) {
            return BOTTOM_RIGHT;
        }
        else if (col_diff < 0 && row_diff == col_diff) {
            return BOTTOM_LEFT;
        }
        else {
            return NONE;
        }
    }
}

int main() {
    std::ofstream fout(getenv("OUTPUT_PATH"));

    int side_length, num_obstacles;
    std::cin >> side_length >> num_obstacles;

    int queen_row, queen_col;
    std::cin >> queen_row >> queen_col;
    Point queen(queen_row, queen_col);

    // create the furthest points the Queen can reach, exclusively, i.e. the
    // queen stops right before these points, and then update them for every
    // obstacle
    Point furthest_B(0, queen_col);
    Point furthest_T(side_length + 1, queen_col);
    Point furthest_L(queen_row, 0);
    Point furthest_R(queen_row, side_length + 1);
    int max_diagonal = std::min(queen_row, queen_col);
    Point furthest_BL(queen_row - max_diagonal, queen_col - max_diagonal);
    max_diagonal = std::min(queen_row, side_length + 1 - queen_col);
    Point furthest_BR(queen_row - max_diagonal, queen_col + max_diagonal);
    max_diagonal = std::min(side_length + 1 - queen_row, queen_col);
    Point furthest_TL(queen_row + max_diagonal, queen_col - max_diagonal);
    max_diagonal = std::min(side_length + 1 - queen_row, side_length + 1 - queen_col);
    Point furthest_TR(queen_row + max_diagonal, queen_col + max_diagonal);

    for (int i = 0; i < num_obstacles; ++i) {
        int obstacle_row, obstacle_col;
        std::cin >> obstacle_row >> obstacle_col;

        Point obstacle(obstacle_row, obstacle_col);
        int distance = getChessDistance(queen, obstacle);

        switch (checkCrossing(queen, obstacle)) {
            case BOTTOM:
                if (distance < getChessDistance(queen, furthest_B)) {
                    furthest_B = obstacle;
                }
                break;
            case TOP:
                if (distance < getChessDistance(queen, furthest_T)) {
                    furthest_T = obstacle;
                }
                break;
            case LEFT:
                if (distance < getChessDistance(queen, furthest_L)) {
                    furthest_L = obstacle;
                }
                break;
            case RIGHT:
                if (distance < getChessDistance(queen, furthest_R)) {
                    furthest_R = obstacle;
                }
                break;
            case BOTTOM_LEFT:
                if (distance < getChessDistance(queen, furthest_BL)) {
                    furthest_BL = obstacle;
                }
                break;
            case BOTTOM_RIGHT:
                if (distance < getChessDistance(queen, furthest_BR)) {
                    furthest_BR = obstacle;
                }
                break;
            case TOP_LEFT:
                if (distance < getChessDistance(queen, furthest_TL)) {
                    furthest_TL = obstacle;
                }
                break;
            case TOP_RIGHT:
                if (distance < getChessDistance(queen, furthest_TR)) {
                    furthest_TR = obstacle;
                }
                break;
            case NONE:
                continue;
        }

    }

    int count_squares =
            getChessDistance(queen, furthest_B)
            + getChessDistance(queen, furthest_T)
            + getChessDistance(queen, furthest_L)
            + getChessDistance(queen, furthest_R)
            + getChessDistance(queen, furthest_BL)
            + getChessDistance(queen, furthest_BR)
            + getChessDistance(queen, furthest_TL)
            + getChessDistance(queen, furthest_TR);

    fout << count_squares << "\n";
    fout.close();

    return 0;
}
