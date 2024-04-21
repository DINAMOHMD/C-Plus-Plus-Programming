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
        tos = 0;
        size = 5;
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
            return 1;
        }
    }
};

int view_content(Stack &s)
{
    int x;
    while (s.pop(&x))
    {
        cout << x << endl;
    }
}

int main()
{
    Stack s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);
    s1.push(5);

    view_content(s1);

    return 0;
}
