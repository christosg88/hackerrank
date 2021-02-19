#include <iostream>

int callA = 0;
int callB = 0;
int callC = 0;

class A
{
protected:
    void func(int  &a)
    {
        a *= 2;
        callA++;
    }
};

class B
{
protected:
    void func(int &a)
    {
        a *= 3;
        callB++;
    }
};

class C
{
protected:
    void func(int &a)
    {
        a *= 5;
        callC++;
    }
};

class D : public A, public B, public C
{
    int val;
public:
    D() : val(1) {}

    void update_val(int new_val)
    {
        while (new_val % 5 == 0)
        {
            new_val /= 5;
            C::func(val);
        }
        while (new_val % 3 == 0)
        {
            new_val /= 3;
            B::func(val);
        }
        while (new_val % 2 == 0)
        {
            new_val /= 2;
            A::func(val);
        }
    }

    // for checking purposes
    void check(int); // do not delete this line
};

void D::check(int new_val)
{
    update_val(new_val);
    std::cout << "Value = " << val << '\n';
    std::cout << "A's func called " << callA << " times" << '\n';
    std::cout << "B's func called " << callB << " times" << '\n';
    std::cout << "C's func called " << callC << " times" << '\n';
}

int main()
{
   D d;
   int new_val;
   std::cin >> new_val;
   d.check(new_val);
}
