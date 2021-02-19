#include <iostream>
#include <string>

int cur_prof_id = 1;
int cur_stud_id = 1;

class Person
{
protected:
    std::string name;
    int age;
    int cur_id;
public:
    Person(int cur_id) : cur_id(cur_id)
    {}
    virtual void getdata() = 0;
    virtual void putdata() = 0;
};

class Professor : public Person
{
    int publications;
public:
    Professor() : Person(cur_prof_id++)
    {}
    void getdata()
    {
        std::cin >> name >> age >> publications;
    }
    void putdata()
    {
        std::cout << name << ' ' << age << ' ' << publications << ' ' << cur_id << '\n';
    }
};

class Student : public Person
{
    int marks[6];
    int sum;
public:
    Student() : Person(cur_stud_id++), sum(0)
    {}
    void getdata()
    {
        std::cin >> name >> age;
        for (register int i = 0; i < 6; ++i)
        {
            std::cin >> marks[i];
            sum += marks[i];
        }
    }
    void putdata()
    {
        std::cout << name << ' ' << age << ' ' << sum << ' ' << cur_id << '\n';
    }
};

int main()
{
    int n, val;
    std::cin >> n;  // the number of objects that is going to be created
    Person *per[n];

    for (int i = 0; i < n; ++i)
    {
        std::cin >> val;
        // if val is 1 current object is of type Professor
        if (val == 1)
            per[i] = new Professor;
        // else the current object is of type Student
        else
            per[i] = new Student;

        per[i]->getdata();  // get the data from the user
    }

    for (int i = 0; i < n; ++i)
        per[i]->putdata();  // print the required output for each object

    return 0;
}
