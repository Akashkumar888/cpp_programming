#include<iostream>
using namespace std;
int main(){
int a=15;
int *p=&a;
//int b=++(*p); // b=16; in this line soon first increment then store
int b=(*p)++; // b=15; in this line soon first store then inreament
cout<<a<<" "<<b<<endl;
    return 0;
}