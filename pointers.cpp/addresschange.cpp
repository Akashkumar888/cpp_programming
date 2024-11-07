#include<iostream>
using namespace std;
void fun(int **p1){
    *p1=*p1+1;
}
int main()
{
    int num=10;
    int *p=&num;
    int **p1=&p;
    cout<<p<<endl;
    fun(p1);
    cout<<p<<endl;
return 0;
}
