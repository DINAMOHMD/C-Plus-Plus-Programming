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
    }
    Stack(int _size)
    {
        tos=0;
        size=_size;
        arr=new int [_size];
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

    }

    int gettos()
    {
        return tos;
    }
    int getsize()
    {
        return size;
    }

    ~Stack()
    {
        delete[]arr;
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
    Stack & operator=(Stack &s)
    {
        int i;
        tos=s.tos;
        size=s.size;
        delete[]arr;
        arr=new int [size];
        for(i=0;i<tos;i++)
        {
            arr[i]=s.arr[i];

        }
        return *this;
    }
   Stack operator+(Stack &s)
{
    Stack result(size+s.size);


    for (int i = 0; i <tos; i++)
    {
        result.push(arr[i]);
    }


    for (int i = 0; i < s.tos; i++)
    {
        result.push(s.arr[i]);
    }

    return result;
}

};


int main()
{
    Stack s1(4);
    s1.push(10);
    s1.push(20);
    Stack s2(10);
    s2.push(4);
    s2.push(5);
    s2.push(1);
    s2.push(2);
    Stack s3=s1+s2;
    cout<<endl<< "tos="<<s3.gettos();
    cout << endl<<"s3 elements: ";
    while (!s3.IsEmpty())
    {
        int element;
        s3.pop(&element);
        cout << element << " ";
    }

    cout<<endl<<"size="<<s3.getsize();


    s1=s2;
    int r=0;
    s1.pop(&r);
    cout<<endl<<r;
    return 0;
}
