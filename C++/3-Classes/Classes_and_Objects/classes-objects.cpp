#include <iostream>
using namespace std;

class Student
{
private:
    int scores[5] = {0};
public:
    Student();
    void Input();
    int CalculateTotalScore();
};

Student::Student()
{
}
void Student::Input()
{
    for (int i = 0; i < 5; ++i)
        cin >> this->scores[i];
}

int Student::CalculateTotalScore()
{
    int sum = 0;
    for (int i = 0; i < 5; ++i)
        sum += this->scores[i];

    return sum;
}

int main()
{
    int n;
    cin >> n;
    Student s[n];

    for(int i = 0; i < n; i++)
        s[i].Input();

    int count = 0;
    int krish_score = s[0].CalculateTotalScore();

    for(int i = 1; i < n; i++)
    {
        int total = s[i].CalculateTotalScore();
        if(total > krish_score)
            count++;
    }

    cout<<count;

    return 0;
}
