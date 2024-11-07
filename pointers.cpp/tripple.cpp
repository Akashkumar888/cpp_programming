
#include<iostream>
using namespace std;
int main()
{
    int num=10;
    int *p=&num;
    int **p2=&p;
    int ***p3=&p2;
    cout<<p<<endl;
    cout<<&p<<endl;
    cout<<p2<<endl;
    cout<<&p2<<endl;
    cout<<p3<<endl;


   ***p3=***p3+10;
   cout<<num<<endl;
return 0;
}