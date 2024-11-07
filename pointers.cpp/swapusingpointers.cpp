#include<iostream>
using namespace std;
void sw(int *ptr1,int *ptr2){
    int temp=*ptr1;
    *ptr1=*ptr2;
    *ptr2=temp;
    cout<<ptr1<<endl;
    cout<<ptr2<<endl;
}
int main()
{
    int a=10,b=40;
    sw(&a,&b);
    cout<<&a<<endl;
    cout<<&b<<endl;
    cout<<a<<" "<<b<<endl;
return 0;
}
