#include<iostream>
using namespace std;
int main(){
    int a,b,c;
    cout<<"Enter the side a: ";
    cin>>a;
    cout<<"Enter the side b: ";
    cin>>b;
    cout<<"Enter the side c: ";
    cin>>c;
    if(a*a+b*b==c*c || b*b+c*c==a*a || c*c+a*a==b*b){
        cout<<"Equilateral triangle";
    }
    else if(a==b || b==c || c==a){
        cout<<"Isosceles triangle";
    }
    else{ // if a!=b!=c
        cout<<"Scalene";
    }
    return 0;
}