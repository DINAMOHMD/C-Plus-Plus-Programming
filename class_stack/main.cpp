#include <iostream>

using namespace std;
class Stack
{
    int arr[5];
    int size;
    int tos;
public:
    Stack()
    {
        tos=0;
        size=5;
    }
    int IsEmpty()
    {
        if(tos==0)
            return 1;
        else
            return 0;
    }
    int IsFull()
    {
        if(tos==size)
            return 1;
        else
            return 0;
    }
    int push (int d)
    {
        if(IsFull()==1)
        {
            cout<<endl<<"stack is full";
            return 0;
        }
        else
        {
            arr[tos]=d;
            tos++;
            return 1;
        }

    }
    int pop (int*d)
    {
        if(IsEmpty()==1)
        {
            cout<<endl<<"stack is empty";
            return 0;
        }
        else
            {
                tos--;
                *d=arr[tos];
                return 1;
            }
    }
};
int main()
{
    Stack s1;
    s1.push(20);
    s1.push(30);
    s1.push(40);
    s1.push(50);
    s1.push(60);
    s1.push(70);
    int x;
    if(s1.pop(&x))
    {
        cout<<endl<<x;
    }
    if(s1.pop(&x))
    {
        cout<<endl<<x;
    }
    if(s1.pop(&x))
    {
        cout<<endl<<x;
    }
    if(s1.pop(&x))
    {
        cout<<endl<<x;
    }
    if(s1.pop(&x))
    {
        cout<<endl<<x;
    }
    if(s1.pop(&x))
    {
        cout<<endl<<x;
    }
    return 0;
}
