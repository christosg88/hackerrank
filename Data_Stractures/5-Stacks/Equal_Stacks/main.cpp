#include <iostream>
#include <vector>

int main() {
    int length1, length2, length3;
    std::cin >> length1 >> length2 >> length3;

    std::vector<int> stack1(length1);
    std::vector<int> stack2(length2);
    std::vector<int> stack3(length3);

    for (int &val : stack1) {
        std::cin >> val;
    }

    for (int &val : stack2) {
        std::cin >> val;
    }

    for (int &val : stack3) {
        std::cin >> val;
    }

    // find the aggregate sum from right to left for each "stack"
    for (int i = length1 - 2; i >= 0; --i) {
        stack1[i] += stack1[i + 1];

    }

    for (int i = length2 - 2; i >= 0; --i) {
        stack2[i] += stack2[i + 1];

    }

    for (int i = length3 - 2; i >= 0; --i) {
        stack3[i] += stack3[i + 1];

    }

    // find the maximum common height
    for (int i1 = 0, i2 = 0, i3 = 0; i1 < length1 && i2 < length2 && i3 < length3;) {
        // base case, we found the maximum common height
        if (stack1[i1] == stack2[i2] && stack2[i2] == stack3[i3]) {
            std::cout << stack1[i1] << '\n';
            return 0;
        }

        // find the stack with the maximum element, and advance it

        if (stack1[i1] >= stack2[i2] && stack1[i1] >= stack3[i3]) {
            ++i1;
        }
        else if (stack2[i2] >= stack1[i1] && stack2[i2] >= stack3[i3]) {
            ++i2;
        }
        else {
            ++i3;
        }
    }

    // no common height was found
    std::cout << 0 << '\n';

    return 0;
}
