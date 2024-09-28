#include<iostream>
using namespace std;
int main(){
    float a,b;
    char op;
    cout<<"Enter the number a :";
    cin>>a;
    cout<<"Enter the operator :";
    cin>>op;
    cout<<"Enter the number b :";
    cin>>b;
    switch(op){
        case '+' :
        cout<<"Sum of two number : "<<a+b;
        break;
        case '-' :
        cout<<"Difference of two number : "<<a-b;
        break;
        case '*' :
        cout<<"Multiplication of two number : "<<a*b;
        break;
        case '/' :
        cout<<"Division of two number : "<<a/b;
        break;
        default :
        cout<<"Invalid operator";
    }
    return 0;
}