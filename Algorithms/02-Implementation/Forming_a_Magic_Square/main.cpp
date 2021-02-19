#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

enum flip_axis {
    HORIZONTALLY,
    VERTICALLY
};

enum roate_direction {
    CLOCKWISE,
    ANTICLOCKWISE
};

void flip(std::vector<std::vector<int>> &nums, flip_axis axis) {
    int length = nums.size();
    int half_length = length / 2;

    if (axis == HORIZONTALLY) {
        for (int i = 0; i < half_length; ++i) {
            for (int j = 0; j < length; ++j) {
                std::swap(nums[i][j], nums[length - 1 - i][j]);
            }
        }
    }
    else {
        for (int i = 0; i < length; ++i) {
            for (int j = 0; j < half_length; ++j) {
                std::swap(nums[i][j], nums[i][length - 1 - j]);
            }
        }
    }
}

void rotate(std::vector<std::vector<int>> &nums, roate_direction direction) {
    int length = nums.size();
    for (int i = 0; i < length - 1; ++i) {
        for (int j = i + 1; j < length; ++j) {
            std::swap(nums[i][j], nums[j][i]);
        }
    }

    flip(nums, direction == CLOCKWISE ? HORIZONTALLY : VERTICALLY);
}

int getDifference(std::vector<std::vector<int>> &nums1, std::vector<std::vector<int>> &nums2) {
    int length = nums1.size();
    int sum = 0;
    for (int i = 0; i < length; ++i) {
        for (int j = 0; j < length; ++j) {
            sum += std::abs(nums1[i][j] - nums2[i][j]);
        }
    }

    return sum;
}

int main() {
    std::ofstream fout(getenv("OUTPUT_PATH"));

    std::vector<std::vector<int>> magic_square = {
        {8, 1, 6},
        {3, 5, 7},
        {4, 9, 2}
    };

    std::vector<std::vector<int>> square(3, std::vector<int>(3));

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cin >> square[i][j];
        }
    }

    // generate all transformations of the given square, and find which is closest to the magic square, since there
    // exists only one 3x3 magic square
    // https://en.wikipedia.org/wiki/Magic_square#Transformations_that_preserve_the_magic_property
    int min_cost = getDifference(magic_square, square);

    flip(square, VERTICALLY);
    min_cost = std::min(min_cost, getDifference(magic_square, square));

    rotate(square, CLOCKWISE);
    min_cost = std::min(min_cost, getDifference(magic_square, square));

    flip(square, HORIZONTALLY);
    min_cost = std::min(min_cost, getDifference(magic_square, square));

    rotate(square, CLOCKWISE);
    min_cost = std::min(min_cost, getDifference(magic_square, square));

    flip(square, VERTICALLY);
    min_cost = std::min(min_cost, getDifference(magic_square, square));

    rotate(square, CLOCKWISE);
    min_cost = std::min(min_cost, getDifference(magic_square, square));

    flip(square, HORIZONTALLY);
    min_cost = std::min(min_cost, getDifference(magic_square, square));

    fout << min_cost << "\n";

    fout.close();
    return 0;
}
