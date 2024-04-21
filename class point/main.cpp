#include <iostream>

using namespace std;
class point2D
{
    int x;
    int y;
    public:
    void setx(int _x)
    {
        x=_x;
    }
    void sety(int _y)
    {
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
    print()
    {
        cout<<"("<<x<<","<<y<<")";
    }
};

int main()
{
    point2D p2d;
    p2d.setx(10);
    p2d.sety(20);
    p2d.print();
    cout<<endl<<p2d.getx();
    cout<<endl<<p2d.gety();


    return 0;
}
