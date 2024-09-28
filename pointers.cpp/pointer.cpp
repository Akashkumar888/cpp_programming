#include<iostream>
using namespace std;
int main(){
int x=9;
int *p=&x;
cout<<&x<<endl;
cout<<p<<endl;
cout<<*p<<endl;
cout<<&(*p)<<endl;
cout<<&p<<endl;
cout<<endl;
float r=9;
float *q=&r;
cout<<&x<<endl;
cout<<q<<endl;
cout<<endl;
char e='S';
char *u=&e;
cout<<&x<<endl;
cout<<u<<endl;
cout<<endl;
bool flag=true;
bool* s=&flag;
cout<<&flag<<endl;
cout<<s<<endl;
    return 0;
}