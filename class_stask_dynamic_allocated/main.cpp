#include <iostream>

using namespace std;

class Stack
{
    int* arr;
    int size;
    int tos;

public:
    Stack()
    {
        tos = 0;
        size=5;
        cout<<"parameterless constructor";
    }
    Stack(int _size)
    {
        tos=0;
        size=_size;
        arr=new int [_size];
        cout<<endl<<"one parameter constructor";
    }
    Stack (Stack const & s) //copy constractor
    {
        int i;
        tos=s.tos;
        size=s.size;
        arr=new int [size];
        for(i=0;i<tos;i++)
        {
            arr[i]=s.arr[i];
        }
        cout<<endl<<"copy constructor";

    }
    ~Stack()
    {
        delete[]arr;
        cout<<endl<<"destructor";
    }
    int IsEmpty()
    {
        if (tos == 0)
            return 1;
        else
            return 0;
    }
    int IsFull()
    {
        if (tos == size)
            return 1;
        else
            return 0;
    }
    int push(int d)
    {
        if (IsFull() == 1)
        {
            cout << endl << "stack is full";
            return 0;
        }
        else
        {
            arr[tos] = d;
            tos++;
            return 1;
        }
    }
    int pop(int *d)
    {
        if (IsEmpty() == 1)
        {
            cout << endl << "stack is empty";
            return 0;
        }
        else
        {
            tos--;
            *d = arr[tos];
            arr[tos]=-1;
            return 1;
        }
    }
};
void view_content(Stack * s3);

void view_content(Stack * s3)
{
    int x;
    while (s3->IsEmpty()!=1)
    {
        s3->pop(&x);
        cout << x <<":" ;
    }
}

int main()
{
    cout<<endl<<"start main";
    Stack s1(5);
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);
    s1.push(5);

    view_content(&s1);
    cout<<endl<<"end main";
// in the end of object s1 go to destractor function and delete array
//in the case object of value ...go to copy constructor and in the end go to destractor for s3&s1
// in the case object by refrence does not go to copy constructor ...in the end go to destructor for s1
// in the case object by address does not go to copy constructor ...in the end go to destructor for s1
    return 0;
}

