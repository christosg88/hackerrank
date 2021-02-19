#include <iostream>
#include <string>
#include <exception>
#include <sstream>

class BadLengthException : public std::exception {
private:
    std::string msg;
public:
    explicit BadLengthException(unsigned long n) : std::exception(), msg(std::to_string(n)) {
    }

    const char *what() const noexcept override {
        return msg.c_str();
    }
};

bool checkUsername(std::string username) {
    unsigned long n = username.length();
    if (n < 5) {
        throw BadLengthException(n);
    }
    else {
        for (size_t i = 0; i < n - 1; ++i) {
            if (username[i] == 'w' && username[i + 1] == 'w') {
                return false;
            }
        }

        return true;
    }
}

int main() {
    int test_cases;
    std::cin >> test_cases;

    while (test_cases--) {
        std::string username;
        std::cin >> username;

        try {
            if (checkUsername(username)) {
                std::cout << "Valid\n";
            }
            else {
                std::cout << "Invalid\n";
            }
        }
        catch (BadLengthException &e) {
            std::cout << "Too short: " << e.what() << '\n';
        }
    }

    return 0;
}
