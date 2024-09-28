#include<iostream>
using namespace std;
int main(){
    int x;
    x = (5>8) ? 10 : 1 != 2 < 5 ? 20 : 30;
    // 1!=2<5 ? 20:30 me (2<5) true hai value 1 hogi (1!=1) false hai then x = 30
    cout<<"Value of x :"<<x;
    return 0;
}