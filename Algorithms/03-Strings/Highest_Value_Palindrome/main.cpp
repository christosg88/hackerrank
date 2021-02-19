#include <iostream>
#include <vector>

int main() {
    int length, half_length, max_changes;
    std::cin >> length >> max_changes;
    half_length = length / 2;

    std::string s;
    std::cin >> s;

    // find the minimum number of changes needed to create a palindrome
    int min_changes = 0;
    for (int i = 0; i < half_length; ++i) {
        if (s[i] != s[length - i - 1]) {
            min_changes++;
        }
    }

    // if the minimum number of changes needed is greater than those allowed, print -1 and return
    if (min_changes > max_changes) {
        std::cout << -1 << '\n';
        return 0;
    }

    // while there remain >= 2 changes, we can change digits from left to right into 9's, so that we increase the value
    // of the number
    int extra_changes = max_changes - min_changes;
    for (int i = 0; i < half_length; ++i) {
        if (s[i] != s[length - i - 1]) {
            // if they are different
            if (s[i] == '9' || s[length - i - 1] == '9') {
                // if one of them is a '9', we don't need any extra change
                s[i] = s[length - i - 1] = '9';
            }
            else {
                // else none of them are a '9'
                if (extra_changes >= 1) {
                    // if we have at least one extra change, we turn them both to '9'
                    s[i] = s[length - i - 1] = '9';
                    extra_changes--;
                }
                else {
                    // else we just turn the smallest to the largest
                    s[i] = s[length - i - 1] = std::max(s[i], s[length - i - 1]);
                }
            }
        }
        else {
            // else they are the same
            if (s[i] != '9' && extra_changes >= 2) {
                // if none of them is '9', and we have at least two extra changes, we turn them both to '9'
                s[i] = s[length - i - 1] = '9';
                extra_changes -= 2;
            }
        }
    }

    // if there remains one final change, and the length is odd, we can change the middle digit to a 9 to increase the
    // value of the number
    if (extra_changes >= 1 && length % 2 == 1) {
        s[length / 2] = '9';
    }

    std::cout << s << '\n';

    return 0;
}
