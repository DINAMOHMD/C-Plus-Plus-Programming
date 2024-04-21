#include <iostream>
#include"graphics.h"
#define NULL
#include<Windows.h>
using namespace std;

class point {
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

class Rect {
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
int main() {
    int gdriver = DETECT, gmode, errorcode;
    initgraph(&gdriver,&gmode,"" );

// رسم الأباجورة
    setcolor(LIGHTGRAY);
    setfillstyle(SOLID_FILL, LIGHTGRAY);
    rectangle(250, 100, 550, 300);
    floodfill(400, 200, LIGHTGRAY);

    // رسم الإضاءة داخل الأباجورة
    setcolor(YELLOW);
    setfillstyle(SOLID_FILL, YELLOW);
    rectangle(250, 100, 550, 300);
    floodfill(400, 200, YELLOW);












    getch();
    closegraph();

    return 0;
}
