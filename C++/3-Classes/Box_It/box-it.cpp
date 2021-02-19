#include <iostream>

int BoxesCreated, BoxesDestroyed;

class Box
{
    // the length, breadth and height of the Box
    int l, b, h;
public:
    Box() : l(0), b(0), h(0)
    {
        BoxesCreated++;
    }
    Box(int l, int b, int h) : l(l), b(b), h(h)
    {
        BoxesCreated++;
    }
    Box(Box &B)
    {
        l = B.l;
        b = B.b;
        h = B.h;
        BoxesCreated++;
    }
    ~Box()
    {
        BoxesDestroyed++;
    }
    int getLength()
    {
        return l;
    }
    int getBreadth()
    {
        return b;
    }
    int getHeight()
    {
        return h;
    }
    long long CalculateVolume()
    {
        long long volume = l;
        volume *= b;
        volume *= h;
        return volume;
    }
    bool operator<(Box &B)
    {
        if (l < B.l)
            return true;
        else if (l == B.l && b < B.b)
            return true;
        else if (l == B.l && b == B.b && h < B.h)
            return true;
        else
            return false;
    }
    // should be
    // friend std::ostream &operator<<(std::ostream &stream, const Box &B)
    friend std::ostream &operator<<(std::ostream &stream, Box B);

};

// should be
// std::ostream &operator<<(std::ostream &stream, const Box &B)
std::ostream &operator<<(std::ostream &stream, Box B)
{
    stream << B.l << ' ' << B.b << ' ' << B.h;
    return stream;
}

void check2()
{
    int n;
    std::cin >> n;

    Box temp;
    for (int i = 0; i < n; ++i)
    {
        int type;
        std::cin >> type;
        if (type == 1)
        {
            std::cout << temp << '\n';
        }
        else if (type == 2)
        {
            int l, b, h;
            std::cin >> l >> b >> h;
            Box NewBox(l, b, h);
            temp = NewBox;
            std::cout << temp << '\n';
        }
        else if (type == 3)
        {
            int l, b, h;
            std::cin >> l >> b >> h;
            Box NewBox(l, b, h);
            if (NewBox < temp)
            {
                std::cout << "Lesser\n";
            }
            else
            {
                std::cout << "Greater\n";
            }
        }
        else if (type == 4)
        {
            std::cout << temp.CalculateVolume() << '\n';
        }
        else if (type == 5)
        {
            Box NewBox(temp);
            std::cout << NewBox << '\n';
        }
    }
}

int main()
{
    BoxesCreated = 0;
    BoxesDestroyed = 0;
    check2();
    std::cout << "Boxes Created : " << BoxesCreated << "\nBoxes Destroyed : " << BoxesDestroyed << '\n';
}
