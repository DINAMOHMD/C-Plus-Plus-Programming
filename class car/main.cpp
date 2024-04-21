#include <iostream>
#include <string.h>
using namespace std;
class car
{
    char color[20];
    int current_speed;
    int max_speed;
    public:
    void setcolor(const char _color[20])
    {
        strcpy(color,_color);
    }
    void setCurrentSpeed(int _currentSpeed)
    {
        current_speed=_currentSpeed;
    }
    void setMaxSpeed(int _maxSpeed)
    {

           max_speed=_maxSpeed;

    }
    int accelerate(int _Speed)
    {
        current_speed+=_Speed;
        if(current_speed >max_speed )
            current_speed=max_speed;

    }
    int deaccelerate(int minspeed)
    {
        current_speed -=minspeed;
        if(current_speed <0 )
            current_speed=0;

    }
    print()
    {
        cout <<color<<":"<<current_speed<<":"<<max_speed;
    }

};
int main()
{
    car c1;
    c1.setcolor("red");
    c1.setCurrentSpeed(90);
    c1.setMaxSpeed(150);
    c1.accelerate(50);
    c1.deaccelerate(100);
    c1.print();

    int acc=c1.accelerate(1000);
    return 0;
}
