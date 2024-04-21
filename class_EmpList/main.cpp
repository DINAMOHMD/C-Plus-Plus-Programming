#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>
#include <string.h>

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
struct emp
{
    int id;
    char name[10];
    int age;
    int salary;
};
class emp_list
{
    struct emp arr[5];
    int size,t,i;
    char ch;
    char menuitems[7][100];
    int x;
    int starting_y;
    int highlighted_color;
    int defaultcolor;
    int num_employees;


public:
    emp_list()
    {
        num_employees=0;
        for (t = 0; t < 7; t++)
    {
        arr[t].id = -1;
    }
    }
    void setmenuitems( char* _menuitems[])
    {
        for (int i = 0; i < 7; i++)
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

            for (t = 0; t < 7; t++)
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
                        cursor = 6;
                    break;
                case 71: // home
                    cursor = 0;
                    break;
                case 80: // down
                    cursor++;
                    if (cursor >6 )
                        cursor = 0;
                    break;
                case 79: // end
                    cursor = 6;
                    break;
                }
                break;
            case 27: // esc
                flag = 1;
                break;
            case 13: // enter
                system("cls");
               if (cursor == 0)
               {
                  New(i);
                  if (i < 5)  // Ensure you don't exceed the array size
                {
                   num_employees++;  // Increment the count of added employees
                }
                getch();
                cursor = 0;
                }

                else if (cursor == 1)
                {
                   DisplayAll();
                    getch();
                    cursor=1;
                }
                else if (cursor == 2)
                {
                    int id;
                    search_by_Id(arr, id);
                    getch();
                    cursor=2;
                }
                else if (cursor == 3)
                {

                    char name[20];
                    cout<<"enter the name to search:";
                    cin>>name;
                    search_by_Name(arr,name, size);
                    getch();
                    cursor=3;
                }
                else if (cursor == 4)
                {
                    int id;
                    Delete_by_Id(id);
                    getch();
                    cursor=4;
                }
                else if (cursor == 5)
                {
                    char name[20];
                    printf("enter the name to delete:");
                    scanf("%s",name);
                    Delete_by_Name(name ,size);
                    getch();
                    cursor=5;
                }

                if (cursor == 6)
                    flag = 1;
                break;
            }
        } while (flag == 0);
    }
    int checkId(int id)
{
    int i;
    for ( i = 0; i < num_employees; i++)
    {
        if (arr[i].id == id)
        {
            return 0;
        }
    }
    return 1;
}
void New(int& index) {
    int validId = 0;
    int Override = 0;

    cout << "enter index of the array: ";
    cin >> index;

    if (index < 0 || index >= 5) {
        cout << "Invalid index. Index should be between 0 and 4." << endl;
        return;
    }

    if (arr[index].id != -1) {
        cout << "This index already contains data. Do you want to override it? (1 for YES, 0 for NO): ";
        cin >> Override;
        if (Override == 0) {
            return;
        }
    }

    while (validId == 0) {
        cout << "enter id of emp: ";
        cin >> arr[index].id;

        validId = checkId(arr[index].id);

        if (validId == 0) {
            cout << "please enter a correct id. This id is already taken." << endl;
        }
    }

    cout << "\n enter name of emp: ";
    cin >> arr[index].name;
    cout << "\n enter age of emp: ";
    cin >> arr[index].age;
    cout << "\n enter salary of emp: ";
    cin >> arr[index].salary;
}

void DisplayAll()
{
    for (int i = 0; i < num_employees; i++)
        {
            if (arr[i].id != -1)
            {
                cout << "id: " << arr[i].id << " name: " << arr[i].name << " age: " << arr[i].age << " salary: " << arr[i].salary << endl;
            }
        }
    }
 void search_by_Id(struct emp arr[],int id)
{
    cout<<"plz enter your id: ";
    cin>>id;
    int i;
    int searched = 0;
    for (i = 0; i <5; i++)
    {
      if(arr[i].id==id)
      {
          cout << "id: " << arr[i].id << " name: " << arr[i].name << " age: " << arr[i].age << " salary: " << arr[i].salary << endl;
          searched = 1;

      }
}
    if (searched)
    {
        cout<<endl<<"Employees  have been existed.";
    }
    else
    {
        cout<<endl<<"No employees found in the database";
    }
}
void search_by_Name(struct emp arr[],  char name[], int size)
{
    int i;
    int searched = 0;
    for (i = 0; i < 5; i++)
    {
        if (strcmp(arr[i].name, name) == 0)
        {
            cout << "id: " << arr[i].id << " name: " << arr[i].name << " age: " << arr[i].age << " salary: " << arr[i].salary << endl;
            searched = 1;
        }
    }

    if (searched)
    {
        cout<<endl<<"Employees  have been existed.";
    }
    else
    {
        cout<<endl<<"No employees found in the database";
    }
}
void Delete_by_Id(int id)
{
    cout<<"plz enter your id: ";
    cin>>id;
    int i;
    int deleted = 0;
    for (i = 0; i <num_employees; i++)
    {
      if(arr[i].id==id)
      {
          arr[i].id=-1;
          deleted = 1;

      }
}
    if (deleted)
    {
        cout<<endl<<"Employees  have been deleted.";
    }
    else
    {
        cout<<endl<<"No employees found in the database";
    }
}
void Delete_by_Name( char name[], int& size)
{
    int i;
    int deleted = 0;
    for (i = 0; i < num_employees; i++)
    {
        if (strcmp(arr[i].name, name) == 0)
        {
            arr[i].id = -1;
            deleted = 1;
        }
    }

    if (deleted)
    {
        cout<<endl<<"Employees  have been deleted.";
    }
    else
    {
        cout<<endl<<"No employees found in the database";
    }
}

};

int main()
{
    emp_list emp1;
     char* items[] = { "add", "display", "searchbyid","searchbyname","deletebyid","deletebyname" ,"exit" };
    emp1.setmenuitems(items);
    emp1.setx(5);
    emp1.sety(10);
    emp1.sethighlighted_color(0x37);
    emp1.setdefaultcolor(0x07);
    emp1.draw();
    return 0;
}
