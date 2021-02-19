#include <iostream>

class Rectangle
{
    int width;
    int height;
public:
    Rectangle() : width(0), height(0) {}

    void Display()
    {
        std::cout << width << ' ' << height << '\n';
    }
    void set_width(int width)
    {
        this->width = width;
    }
    void set_height(int height)
    {
        this->height = height;
    }
    int get_width()
    {
        return width;
    }
    int get_height()
    {
        return height;
    }
};

class RectangleArea : public Rectangle
{
public:
    void Input()
    {
        int width, height;
        std::cin >> width >> height;
        set_width(width);
        set_height(height);
    }
    void Display()
    {
        std::cout << get_width() * get_height() << '\n';
    }
};

int main()
{
    RectangleArea r_area;

    r_area.Input();
    Rectangle *r;
    r = &r_area;
    r->Display();
    r_area.Display();

    return 0;
}
