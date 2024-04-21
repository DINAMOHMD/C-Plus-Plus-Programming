#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#include <Windows.h>
#include<string.h>
#define null -32

using namespace std;

void gotoxy(int x,int y)
 {
   COORD coord={0,0};
   coord.X=x;
   coord.Y=y;
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
 }
void textattr(int i)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);
}

class menu
{
    char menuitems[3][10];
    int x;
    int starting_y;
    int highlighted_color;
    int defaultcolor;

public:
    void setmenuitems( char* _menuitems[])
    {
        for (int i = 0; i < 3; i++)
        {
            strcpy(menuitems[i], _menuitems[i]);
        }
    }

    void setx(int _x)
    {
        x = _x;
    }

    void sety(int _y)
    {
        starting_y = _y;
    }

    void sethighlighted_color(int _c)
    {
        highlighted_color = _c;
    }

    void setdefaultcolor(int _c1)
    {
        defaultcolor = _c1;
    }

    void draw()
    {
        char ch;
        int t, cursor = 0, flag = 0;

        do {
            system("cls");

            for (t = 0; t < 3; t++)
            {
                gotoxy(starting_y, x + t);
                if (t == cursor)
                    textattr(highlighted_color);
                cout << menuitems[t];
                textattr(defaultcolor);
            }

            ch = getch();
            switch (ch)
            {
            case -32:
                ch = getch();
                switch (ch)
                {
                case 72: // up
                    cursor--;
                    if (cursor < 0)
                        cursor = 2;
                    break;
                case 71: // home
                    cursor = 0;
                    break;
                case 80: // down
                    cursor++;
                    if (cursor > 2)
                        cursor = 0;
                    break;
                case 79: // end
                    cursor = 2;
                    break;
                }
                break;
            case 27: // esc
                flag = 1;
                break;
            case 13: // enter
                system("cls");
                cout << menuitems[cursor];
                getch();
                if (cursor == 2)
                    flag = 1;
                break;
            }
        } while (flag == 0);
    }
};

int main()
{
    menu m1;
     char* items[] = { "new", "display", "exit" };
    m1.setmenuitems(items);
    m1.setx(5);
    m1.sety(10);
    m1.sethighlighted_color(0x37);
    m1.setdefaultcolor(0x07);
    m1.draw();
    return 0;
}

