//Operator Overloading
#include <iostream>
#include <string>

class Complex
{
public:
    int a,b;
    void input(std::string s)
    {
        int i = 0;

        int v1 = 0;
        while (s[i] != '+')
        {
            v1 = v1*10 + s[i] - '0';
            i++;
        }

        while (s[i] == ' ' || s[i] == '+' || s[i] ==' i')
        {
            i++;
        }

        int v2 = 0;
        while (i < s.length())
        {
            v2 = v2*10 + s[i] - '0';
            i++;
        }

        a = v1;
        b = v2;
    }
};

/**
 * Overloads the + operator
 */
Complex operator+(Complex &ob1, Complex &ob2)
{
    Complex tmp;
    tmp.a = ob1.a + ob2.a;
    tmp.b = ob1.b + ob2.b;

    return tmp;
}

/**
 * Overloads the << operator
 */
std::ostream &operator<<(std::ostream &stream, Complex &ob)
{
    stream << ob.a << "+i" << ob.b;
    return stream;
}

int main()
{
    Complex x, y;
    std::string s1, s2;
    std::cin >> s1;
    std::cin >> s2;
    x.input(s1);
    y.input(s2);
    Complex z = x + y;
    std::cout << z << std::endl;
}
