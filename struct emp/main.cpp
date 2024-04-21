#include <iostream>

using namespace std;
struct emp
{
    int id;
    char name[10];
    int salary;
    public:
    print()
    {
        cout <<id<<":"<<name<<":"<<salary;
    }
};

int main()

{

    emp e1={1,"dina",4000};
    e1.print();

    return 0;
}
