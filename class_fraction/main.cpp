#include <iostream>

using namespace std;
class fraction
{
    int num;
    int denum;
public:
    fraction(int _num=0,int _denum=1)
    {
        num=_num;
        denum=_denum;
    }
    void setnum(int _num)
    {
        num=_num;
    }
    void setdenum(int _denum)
    {
        denum=_denum;
    }
    void setfraction(int _num,int _denum)
    {
        num=_num;
        denum=_denum;
    }
    int getnum()
    {
        return num;
    }
    int getdenum()
    {
        return denum;
    }
    fraction operator+(fraction &f)
    {
        fraction res;
        res.num=(num*f.denum)+(f.num*denum);
        res.denum=(denum*f.denum);
        return res;
    }
    fraction operator+(int n)
    {
        fraction res;
        res.num=num+(n*denum);
        res.denum=denum;
        return res;
    }
     fraction operator-(fraction &f)
    {
        fraction res;
        res.num=(num*f.denum)-(f.num*denum);
        res.denum=(denum*f.denum);
        return res;
    }
    fraction operator-(int n)
    {
        fraction res;
        res.num=num-(n*denum);
        res.denum=denum;
        return res;
    }
    fraction operator*(fraction &f)
    {
        fraction res;
        res.num=num*f.num;
        res.denum=denum*f.denum;
        return res;
    }
    fraction operator*(int n)
    {
        fraction res;
        res.num=num*n;
        res.denum=denum;
        return res;
    }
    fraction operator/(fraction &f)
    {
        if(f.num==0)
        {
            cout<<"Error: Division by zero."<<endl;
        }
        else
        {
            fraction res;
            res.num=num*f.denum;
            res.denum=f.num*denum;
            return res;
        }
    }
        fraction operator/(int n)
        {
             if(n==0)
             {
                cout<<"Error: Division by zero."<<endl;
             }
             else
             {
                 fraction res;
                 res.num=num;
                 res.denum=denum*n;
                 return res;
             }
        }
        void simplify()
        {
             int sign = (num < 0) ? -1 : 1;
             int dsign = (denum < 0) ? -1 : 1;
             num = sign * num;
             denum = dsign * denum;
            for(int i=2 ;i<=num&&i<=denum;i++)
            {
                while(num%i==0&&denum%i==0)
                {
                    num/=i;
                    denum/=i;
                }
            }
             if (sign == -1 && dsign == 1)
             {
                num *= sign;
             }
            else if (dsign == -1 && sign == 1)
             {
               num *= dsign;
             }
        }
        void print()
        {
            cout<<num<<"/"<<denum <<endl;
        }
};
int main()
{
    fraction f1(1, 2);
    fraction f2(3, 4);


    fraction sumResult = f1 + f2;
    sumResult.simplify();
    cout << "Sum: ";
    sumResult.print();



    fraction subtractResult = f1 - f2;
    subtractResult.simplify();
    cout << "Subtraction: ";
    subtractResult.print();



    fraction multiplyResult = f1 * f2;
    cout << "Multiplication: ";
    multiplyResult.print();



    fraction divideResult = f1 / f2;
    divideResult.simplify();
    cout << "Division: ";
    divideResult.print();

    fraction sumWithInteger = f1 + 3;
    cout << "Sum with integer: ";
    sumWithInteger.print();



    fraction subtractFromInteger = f1 - 2;
    cout << "Subtract from integer: ";
    subtractFromInteger.print();



    fraction multiplyByInteger = f1 * 5;
    cout << "Multiply by integer: ";
    multiplyByInteger.print();



    fraction divideByInteger = f1 / 4;
    cout << "Divide by integer: ";
    divideByInteger.print();

    fraction f3(8,-12);
    cout << "Simplify: ";
    f3.simplify();
    f3.print();

}
