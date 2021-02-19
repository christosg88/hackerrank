#include <iostream>
#include <string>

template<class T> class AddElements
{
    T value;
public:
    AddElements(T value) : value(value)
    {}
    T add(T value2)
    {
        return value + value2;
    }
};
template<> class AddElements<std::string>
{
    std::string value;
public:
    AddElements(std::string value) : value(value)
    {}
    std::string concatenate(std::string value2)
    {
        std::string tmp = value + value2;
        return tmp;
    }
};

int main ()
{
    int lines;
    std::cin >> lines;

    for (int i = 0; i < lines; ++i)
    {
        std::string type;
        std::cin >> type;
        if (type == "float")
        {
            double element1, element2;
            std::cin >> element1 >> element2;
            AddElements<double> myfloat(element1);
            std::cout << myfloat.add(element2) << '\n';
        }
        else if (type == "int")
        {
            int element1, element2;
            std::cin >> element1 >> element2;
            AddElements<int> myint(element1);
            std::cout << myint.add(element2) << '\n';
        }
        else if (type == "string")
        {
            std::string element1, element2;
            std::cin >> element1 >> element2;
            AddElements<std::string> mystring(element1);
            std::cout << mystring.concatenate(element2) << '\n';
        }
    }
    return 0;
}
