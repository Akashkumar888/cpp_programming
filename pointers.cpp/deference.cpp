#include<iostream>
using namespace std;
int main(){
int x=89;
int* p=&x;
cout<<*p<<endl;
x=45;
cout<<x<<endl;
*p=23;
cout<<x<<endl;
cout<<*p<<endl;
    return 0;
}