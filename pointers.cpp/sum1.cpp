#include<iostream>
using namespace std;
int main(){
int a,b;
int*p1=&a;
int*p2=&b;
cin>>*p1;
cin>>*p2;
cout<<*p1+*p2<<endl;
cout<<a+b;
    return 0;
}