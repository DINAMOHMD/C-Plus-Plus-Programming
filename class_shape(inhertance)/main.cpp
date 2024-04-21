#include <iostream>

using namespace std;
class shape
{
protected:
    int dim1;
    int dim2;
public:
    shape(){dim1=dim2=1;}
    shape(int dim){dim1=dim2=dim;}
    shape(int _dim1,int _dim2)
    {
        dim1=_dim1;
        dim2=_dim2;
    }
    void setdim1(int _dim1){dim1=_dim1;}
    void setdim2(int _dim2){dim2=_dim2;}
    int getdim1(){return dim1;}
    int getdim2(){return dim2;}
    void print()
    {
        cout<<"("<<dim1<<","<<dim2<<")";
    }
};
class rect:public shape
{
public:
    rect(){}
    rect(int _dim1,int _dim2):shape(_dim1,_dim2){}
    float calcArea()
    {
        return dim1*dim2;
    }
};
class triangle:public shape
{
public:
    triangle(){}
    triangle(int _dim1,int _dim2):shape(_dim1,_dim2){}
    float calcArea()
    {
        return 0.5*dim1*dim2;
    }
};
class circle :public shape
{
public:
    circle(){}
    circle(int _dim):shape(_dim){}
    void setdim1(int _dim1)
    {
        dim1=_dim1;
        dim2=_dim1;
    }
    void setdim2(int _dim){dim1=dim2=_dim;}
    float calcArea()
    {
        return 3.14*dim1*dim2;
    }
};
class square :public shape
{
public:
    square(){}
    square(int _dim):shape(_dim){}
    void setdim1(int _dim1)
    {
        dim1=_dim1;
        dim2=_dim1;
    }
    void setdim2(int _dim){dim1=dim2=_dim;}
    float calcArea()
    {
        return dim1*dim2;
    }
};
void printShapeArea(shape s)
{
    s.print();
}
int main()
{
    rect r1(10,20);
    cout<<endl<<r1.calcArea();
    printShapeArea(r1);
    triangle t1(70,10);
    cout<<endl<<t1.calcArea();
    printShapeArea(t1);
    circle c1(10);
    cout<<endl<<c1.calcArea();
    printShapeArea(c1);
    square s1(70);
    cout<<endl<<s1.calcArea();
    printShapeArea(s1);

    return 0;
}
