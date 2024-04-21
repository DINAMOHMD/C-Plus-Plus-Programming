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
    Complex add(Complex c)
    {
        Complex res;
        res.real=c.real+real;
        res.img=c.img+ img;
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
Complex add(Complex c1,Complex c2);
int main()
{
    Complex c1(2,6),c2,c3;
    c2.setreal(5);
    c2.setimg(-7);
    c3=c1.add(c2);
    c3.print();
    c1.setreal(8);
    c1.setimg(10);
    c2.setreal(2);
    c2.setimg(-3);
    c3=add(c1,c2);
    c3.print();
    return 0;
}
Complex add(Complex c1,Complex c2)
    {
        Complex res;
        res.setreal(c1.getreal()+c2.getreal());
        res.setimg(c1.getimg()+c2.getimg());
        return res;
    }
