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
    virtual void print()
    {
        cout<<"("<<dim1<<","<<dim2<<")";
    }
    virtual float calcArea()=0; //pure virtual function

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
void printShapeArea(shape *s)
{
    s->print();
}
void printArea(shape *s)
{
    cout<< s->calcArea()<<endl;
}
int main()
{
    rect r1(10,20);
    printShapeArea(&r1);
    printArea(&r1);
    triangle t1(70,10);
    printShapeArea(&t1);
    printArea(&t1);
    circle c1(10);
    printShapeArea(&c1);
    printArea(&c1);
    square s1(70);
    printShapeArea(&s1);
    printArea(&s1);
    shape * arrr[3]={&r1,&t1,&c1};
    float sum=0;
    for(int i=0;i<3;i++)
    {
        sum+=arrr[i]->calcArea();
    }
    cout<<"sum="<<sum;

    return 0;
}
