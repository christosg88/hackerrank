#include <iostream>

class Person {
public:
    Person(std::string first_name, std::string last_name) : first_name(std::move(first_name)), last_name
            (std::move(last_name)) {
    }

    const std::string &get_first_name() const {
        return first_name;
    }

    const std::string &get_last_name() const {
        return last_name;
    }

private:
    std::string first_name;
    std::string last_name;
};

std::ostream &operator<<(std::ostream &stream, const Person &p) {
    stream << "first_name=" << p.get_first_name() << ",last_name=" << p.get_last_name();

    return stream;
}

int main() {
    std::string first_name, last_name, event;
    std::cin >> first_name >> last_name >> event;
    auto p = Person(first_name, last_name);
    std::cout << p << " " << event << "\n";

    return 0;
}
