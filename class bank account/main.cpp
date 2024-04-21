#include <iostream>
#include<string.h>
using namespace std;

class bank_account
{
    int id;
    char name[20];
    int balance;
public:
    print()
    {
        cout <<id<<":"<<name<<":"<<balance;
    }
    void setId(int _id)
    {
        id=_id;
    }
    void setName(const char _name[10])
    {
        strcpy(name, _name);
    }
    void setbalance(int _balance)
    {
        balance=_balance;
    }
    int withdraw(int _many)
    {
        if(_many <=balance)
            balance-=_many;
    }
    int deposite(int _dmany)
    {
        balance += _dmany;
    }

};
int main()
{
    bank_account bc1;
    bc1.setId(1);
    bc1.setName("dina");
    bc1.setbalance(200);
    bc1.withdraw(300);
    bc1.deposite(40);
    bc1.print();
    return 0;
}
