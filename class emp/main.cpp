#include <iostream>
#include <string.h>
using namespace std;

class emp
{
    int id;
    char name[10];
    int salary;
    public:
    print()
    {
        cout <<id<<":"<<name<<":"<<salary;
    }
    void setId(int _id)
    {
        id=_id;
    }
    void setName(const char _name[10])
    {
        strcpy(name, _name);
    }
    void setSalary(int _salary)
    {
        salary=_salary;
    }
    int getid()
    {
        return id;
    }
    char* getname()
    {
        return name;
    }
    int getsalary()
    {
        return salary;
    }
};
int main()
{
    emp e1;
    e1.setId(1);
    e1.setName("dina");
    e1.setSalary(4000);
    e1.print();

    cout<<endl<<e1.getid();
    cout<<endl<<e1.getname();
    cout<<endl<<e1.getsalary();
    return 0;
}
