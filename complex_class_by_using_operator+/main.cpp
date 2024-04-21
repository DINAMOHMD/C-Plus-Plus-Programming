#include <iostream>

using namespace std;

class Complex
{
    int real;
    int img;
public:
    Complex()//parameterless  constructor
    {
        real=0;
        img=0;
    }
    Complex(int _real,int _img)
    {
        real=_real;
        img=_img;
    }
    void setreal(int _real)
    {
        real=_real;
    }
    void setimg(int _img)
    {
        img=_img;
    }
    int getreal()
    {
        return real;
    }
    int getimg()
    {
        return img;
    }
    Complex & operator+(Complex c)
    {
        Complex res;
        res.real=c.real+real;
        res.img=c.img+ img;
        return res;
    }
    Complex & operator+(int r)
    {
        Complex res(real+r,img);

        return res;
    }
    void print()
    {
        if(img >0)
            cout<< endl<<real<<"+"<<img<<"j";
        else if(img<0)
            cout<< endl<<real<<img<<"j";
        else
            cout<< endl<<real;


    }
};
Complex & operator+(int r,Complex& c);
int main()
{
    Complex c1(2,6),c2,c3,c4;
    c3=10+c1;
    c2=c1+4;
    c4=c1+c2+c3;
    c1=c2;
    c1.print();
    c3.print();
    c2.print();
    c4.print();
    return 0;
}

Complex & operator+(int r,Complex& c)
{
    return c+r;
}
