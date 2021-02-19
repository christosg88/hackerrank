#include <iostream>
using namespace std;

const char* int_name(int num);

int main()
{
    int a, b;
    cin >> a >> b;

    for (int i = a; i <= b; ++i)
    {
        cout << int_name(i);
    }

    return 0;
}

const char* int_name(int num)
{
    switch (num)
    {
        case 1:
            return "one\n";
            break;
        case 2:
            return "two\n";
            break;
        case 3:
            return "three\n";
            break;
        case 4:
            return "four\n";
            break;
        case 5:
            return "five\n";
            break;
        case 6:
            return "six\n";
            break;
        case 7:
            return "seven\n";
            break;
        case 8:
            return "eight\n";
            break;
        case 9:
            return "nine\n";
            break;
        default:
            if (num % 2)
                return "odd\n";
            else
                return "even\n";
    }
}
