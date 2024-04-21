#include <iostream>
#include <string.h>
using namespace std;
class person
{
protected:
    int id;
    char name[10];
    int age;
public:
    person ()
    {id=0;
    strcpy(name,"no name");
    age=6;
    }
    person (int _id,char * _name,int _age)
    {
        id=_id;
        age=_age;
        strcpy(name,_name);
    }
    void setid(int _id){id=_id;}
    void setname(char *_name){strcpy(name,_name);}
    void setage(int _age){age=_age;}
    int getid(){return id;}
    char *getname(){return name;}
    int getage(){return age;}
    void print(){cout<< endl<<id<<":"<<name<<":"<<age;}


};
class student:public person
{
    char grade;
public:
    student(){}
    student(int _id,char * _name, int _age):person(_id,_name,_age){grade='f';}
    void setage(int _age)
    {
        if(_age>6)
            age=_age;
        else
            cout<<" invalid age for student";
    }
    void setgrade(char _grade)
    {
        grade=_grade;
    }
    char getgrade(){return grade;}
    void print()
    {
        person::print();
        cout<<":"<<grade;}
};
class instructor:public person
{
    float salary;
public:
    instructor(){}
    instructor(int _id,char * _name, int _age):person(_id,_name,_age){salary=3000;}
    void setage(int _age)
    {
        if(_age>=30)
            age=_age;
        else
            cout<<" invalid age for instructor";
    }
    void setsalary(char _salary)
    {
        salary=_salary;
    }
    char getsalary(){return salary;}
    void print()
    {
        person::print();
        cout<<":"<<salary;}
};
int main()
{
    student s1(1,"dina",20);
    s1.print();
    instructor i1(2,"omar",30);
    i1.print();
    return 0;
}
