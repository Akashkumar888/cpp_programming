#include<iostream>
using namespace std;
int main(){
    int a,b;
    cout<<"Enter the length: ";
    cin>>a;
    cout<<"Enter the breadth: ";
    cin>>b;
    if((a*b)>(2*(a+b))){
        cout<<"Area is greater than its Perimetre";
    }
    else{
        cout<<"Perimetre is greater than its area";
    }
    return 0;
}