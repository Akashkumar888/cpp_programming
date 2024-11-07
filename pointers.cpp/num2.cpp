

#include<iostream>
using namespace std;
void incr(int *ptr){
    *ptr=*ptr+1;
}
int main()
{
    int num=10;
    incr(&num);
    cout<<num<<endl;
return 0;
}