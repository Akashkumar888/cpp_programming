
#include<iostream>
using namespace std;
int main()
{
    int *ptr=new int;
    cout<<ptr<<endl;
    *ptr=41;
    cout<<*ptr<<endl;
    float *ptr1=new float;
    cout<<ptr1<<endl;
    *ptr1=12.3;
    cout<<*ptr1<<endl;
    delete ptr;
    delete ptr1;
return 0;
}
