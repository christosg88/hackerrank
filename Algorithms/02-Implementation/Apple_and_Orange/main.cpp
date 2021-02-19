#include <iostream>

int main() {
    int house_start, house_end;
    std::cin >> house_start >> house_end;

    int apple_tree, orange_tree;
    std::cin >> apple_tree >> orange_tree;

    int apple_house_min_distance = house_start - apple_tree;
    int apple_house_max_distance = house_end - apple_tree;
    int orange_house_min_distance = orange_tree - house_end;
    int orange_house_max_distance = orange_tree - house_start;

    int num_apples, num_oranges;
    std::cin >> num_apples >> num_oranges;

    int num_apples_in_house, num_oranges_in_house;
    num_apples_in_house = num_oranges_in_house = 0;

    for (int i = 0; i < num_apples; ++i) {
        int apple_dist;
        std::cin >> apple_dist;

        if (apple_dist >= apple_house_min_distance && apple_dist <= apple_house_max_distance) {
            ++num_apples_in_house;
        }
    }

    for (int i = 0; i < num_oranges; ++i) {
        int orange_dist;
        std::cin >> orange_dist;
        orange_dist = -orange_dist;

        if (orange_dist >= orange_house_min_distance && orange_dist <= orange_house_max_distance) {
            ++num_oranges_in_house;
        }
    }

    std::cout << num_apples_in_house << std::endl << num_oranges_in_house << std::endl;

    return 0;
}
