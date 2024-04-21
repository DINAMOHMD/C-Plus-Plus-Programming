#include <iostream>

using namespace std;

class Queue
{
    int* arr;
    int size;
    int front;
    int rear;

public:
    Queue(int _size)
    {
        size = _size;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    Queue(const Queue& q)
    {
        size = q.size;
        arr = new int[size];
        front = q.front;
        rear = q.rear;

        for (int i = 0; i < size; i++)
        {
            arr[i] = q.arr[i];
        }
    }

    ~Queue()
    {
        delete[] arr;
    }

    int IsEmpty() {
        return front == -1;
    }

    int IsFull() {
        return (front == 0 && rear == size - 1) || (rear == (front - 1) );
    }

    int enqueue(int d) {
        if (IsFull()) {
            cout << "Queue is full" << endl;
            return false;
        }
        if (front == -1) {
            front = rear = 0;
        }
        else {
            rear = (rear + 1) % size;
        }
        arr[rear] = d;
        return true;
    }

    int dequeue(int& d)
    {
        if (IsEmpty())
        {
            cout << "Queue is empty" << endl;
            return false;
        }
        d = arr[front];
        if (front == rear) {
            front = rear = -1;
        }
        else {
            front = (front + 1) % size;
        }
        return true;
    }

    Queue& operator=(const Queue &s)
    {
        if (this == &s) {
            return *this;
        }

        delete[] arr;
        size = s.size;
        arr = new int[size];
        front = s.front;
        rear = s.rear;
        for (int i = 0; i < size; i++) {
            arr[i] = s.arr[i];
        }

        return *this;
    }

    Queue operator+(const Queue &s)
    {
        Queue result(size + s.size);

        for (int i = front; i <= rear; i++) {
            result.enqueue(arr[i]);
        }

        for (int i = s.front; i <= s.rear; i++) {
            result.enqueue(s.arr[i]);
        }

        return result;
    }
    void peak()
    {
        cout<<"the element is="<< arr[front]<<endl;
    }
};

void view_content(Queue& s3)
{
    int x;
    while (!s3.IsEmpty())
    {
        s3.dequeue(x);
        cout << x << ": ";
    }
    cout << endl;
}

int main()
{
    Queue s1(4);
    s1.enqueue(10);
    s1.enqueue(20);

    s1.peak();

    Queue s2(4);
    s2.enqueue(4);
    s2.enqueue(5);

    int d = 0;
    s2.dequeue(d);

    s2.enqueue(1);
    s2.enqueue(2);
    s2.enqueue(9);

    view_content(s2);

    s2.enqueue(1);
    s2.enqueue(2);
    s2.enqueue(9);
    s2.enqueue(11);

    s2.peak();


    Queue s3 = s1 + s2;

    cout << endl << "s3 elements: ";
    view_content(s3);

    s1 = s2;
    view_content(s2);
    view_content(s1);

    return 0;
}
