#include <iostream>

using namespace std;

int main()
{
    int Size ,i;
    cout<<"enter the size of array:"<<endl;
    cin >> Size;
    int *arr=new int[Size];
    for(i=0;i<Size;i++)
    {
        cout<<"enter the element no " << i+1<<"of array:";
        cin>>arr[i];
    }
    for(i=0;i<Size;i++)
    {
        cout<<arr[i]<<"\t";
    }
    delete [] arr;

    return 0;
}
