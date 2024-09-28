#include<iostream>
using namespace std;
int main(){
    int a,b,c;
    cout<<"Enter 1st number :";
    cin>>a;
    cout<<"Enter 2nd number :";
    cin>>b;
    cout<<"Enter 3rd number :";
    cin>>c;
    if(a>b && a>c){
        cout<<"Laregest number is :"<<a<<endl;
    }
    if(b>c && b>a){
        cout<<"Largest number is :"<<b<<endl;
    }
    if(c>a && c>b){
        cout<<"Laregest number is :"<<c<<endl;
    }
    return 0;
}
