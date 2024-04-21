#include <iostream>
#include"graphics.h"
#define NULL
#include<Windows.h>
using namespace std;

class point
{
    int x;
    int y;
public:
    point()
    {
        cout<<"\n point parameterless constructor";
        x=y=0;
    }
    point(int _r)
    {
        cout<<"\n point one parameter constructor";
        x=y=_r;
    }
    point(int _x,int _y)
    {
        cout<<"\n point 2 parameters  constructor";
        x=_x;
        y=_y;
    }
    void setx(int _x)
    {
        x=_x;
    }
    void sety(int _y)
    {
        y=_y;
    }
    void setpoint(int _x,int _y)
    {
        x=_x;
        y=_y;
    }
    int getx()
    {
        return x;
    }
    int gety()
    {
        return y;
    }
    void print()
    {
        cout<<"("<<x<<","<<y<<")";
    }
};
class Rect
{
    point ul;
    point lr;
public:
    Rect() : ul(0,0),lr(0,0)
    {
        cout<<"\n rectangle parameterless constractor";

    }
    Rect(int x1,int y1,int x2,int y2):ul(x1,y1),lr(x2,y2)
    {
        cout<<"rectangle 4 parameters constructor";
    }
    void setlr(point _lr)
    {
        lr=_lr;
    }
    void setlr(int x,int y)
    {
        ul.setpoint(x,y);
    }
    void setul(point _ul)
    {
        ul=_ul;
    }
    void setul(int x, int y)
    {
        ul.setpoint(x,y);
    }
    point getul()
    {
        return ul;
    }
    point getlr()
    {
        return lr;
    }
    void setrect(point _ul,point _lr)
    {
        ul=_ul;
        lr=_lr;
    }
    void setrect(int x1,int y1, int x2,int y2)
    {
        ul.setpoint(x1,y1);
        lr.setpoint(x2,y2);
    }
    void print()
    {
        cout<<"upper left point:";
        ul.print();
        cout<<"\n lower right point:";
        lr.print();
    }
    void draw()
    {
        rectangle(ul.getx(),ul.gety(),lr.getx(),lr.gety());
    }
};
class Line
{
     point start;
    point endp;
public:
    Line() : start(0,0),endp(0,0)
    {
        cout<<"\n rectangle parameterless constractor";

    }
    Line(int x1,int y1,int x2,int y2):start(x1,y1),endp(x2,y2)
    {
        cout<<"rectangle 4 parameters constructor";
    }
    void setstart(point _start)
    {
        start=_start;
    }
    void setstart(int x,int y)
    {
        start.setpoint(x,y);
    }
    void setendp(point _endp)
    {
        endp=_endp;
    }
    void setendp(int x, int y)
    {
        endp.setpoint(x,y);
    }
    point getendp()
    {
        return endp;
    }
    point getstart()
    {
        return start;
    }
    void setline(point _start,point _endp)
    {
        start=_start;
        endp=_endp;
    }
    void setline(int x1,int y1, int x2,int y2)
    {
        start.setpoint(x1,y1);
        endp.setpoint(x2,y2);
    }
    void print()
    {
        cout<<"\n start point:";
        start.print();
        cout<<"\n end point:";
        endp.print();
    }
    void draw()
    {
        line(start.getx(),start.gety(),endp.getx(),endp.gety());
    }
};
class Circle
{
    point center;
    int rad;
public:
    Circle()
    {
        rad=1;
    }
    Circle (int _x,int _y,int _rad):center(_x,_y)
    {
        rad=_rad;
    }
    void setcenter(int x, int y)
    {
        center.setpoint(x,y);
    }
    void setcenter(point _center)
    {
        center=_center;
    }
    void setrad(int _rad)
    {
        rad=_rad;
    }
    void print()
    {
        center.print();
        cout<<"rad="<<rad;
    }
    void draw()
    {
        circle(center.getx(),center.gety(),rad);
    }


};
class Triangle
{
    point X;
    point Y;
    point Z;
    public:

    Triangle():X(0,0),Y(0,0),Z(0,0)
    {
        cout<<"triangle parameterless constructor";
    }
    Triangle(int x1,int y1,int x2,int y2,int x3,int y3):X(x1,y1),Y(x2,y2),Z(x3,y3)
    {

    }
    void setX(point _X)
    {
        X=_X;
    }
    void setY(point _Y)
    {
        Y=_Y;
    }
    void setZ(point _Z)
    {
        Z=_Z;
    }
    void setX(int x,int y)
    {
        X.setpoint(x,y);
    }
    void setY(int x,int y)
    {
        Y.setpoint(x,y);
    }
    void setZ(int x,int y)
    {
        Z.setpoint(x,y);
    }
    void draw()
    {
        Line l1(X.getx(),X.gety(),Y.getx(),Y.gety());
        Line l2(Y.getx(),Y.gety(),Z.getx(),Z.gety());
        Line l3(Z.getx(),Z.gety(),X.getx(),X.gety());
        l1.draw();
        l2.draw();
        l3.draw();

    }
};
int main()
{
   int gdriver=DETECT,gmode,errorcode;
   initgraph(&gdriver,&gmode,"" );
   Rect r(10,20,100,200);
   r.draw();
    Line l(10,20,100,200);
   l.draw();
   Circle c(100,200,50);
   c.draw();
   Triangle t(300,200,100,500,200,300);
   t.draw();
   getch();

   closegraph();

    return 0;
}
