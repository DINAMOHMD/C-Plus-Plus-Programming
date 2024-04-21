#include <iostream>
#include<string.h>
using namespace std;
class person
{
protected:
    int id;
    char name[10];
    int age;
public:
    person()
    {id=0;
    strcpy(name,"no name");
    age=6;
    }
    person(int _id,char *_name,int _age)
    {
        id=_id;
        strcpy(name,_name);
        age=_age;

    }
    void setid(int _id){id=_id;}
    void setname(char*_name){strcpy(name,_name);}
    void setage(int _age){age=_age;}
    int getid(){return id;}
    char*getname(){return name;}
    int getage(){return age;}
    void print(){cout<<endl<<id<<":"<<name<<":"<<age;}
};
class student:public person
{
    char grade;
public:
    student(int _id,char *_name,int _age ):person(_id,_name,_age)
    {
        grade='f';
    }
    void setgrade(char _grade)
    {
        grade=_grade;
    }
    char getgrade(){return grade;}
    void setage(int _age)
    {
        if(_age>6)
            age=_age;
        else
            cout<<"invalid age for student";
    }
    void print()
    {
        person::print();
        cout<<":"<< grade;}
};

class instructor:public person
{
    float salary;
public:
    instructor()
    {salary=1000;}
    instructor(int _id,char *_name,int _age):person(_id,_name,_age)
    {
        salary=3000;
    }
    void setsalary(float _salary){salary=_salary;}
    float getsalary(){return salary;}
    void setage(int _age)
    {
        if(_age>=30)
            age=_age;
        else
             cout<<"invalid age for instructor";

    }
    void print()
    {
        person::print();
        cout<<":"<<salary;
    }
};



int main()
{
   student s1(1,"dina",10);
   s1.print();
   instructor i1;
   i1.setid(2);
   i1.setname("omar");
   i1.setage(31);
   i1.print();
    return 0;
}
