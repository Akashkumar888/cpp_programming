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
    if(a>b){
        if(a>c){
            cout<<a<<" Largest number"<<endl;
        }
        else{
            cout<<c<<" Largest number"<<endl;
        }
    }
    else{
        if(b>c){
            cout<<b<<" Largest number"<<endl;
        }
        else{
            cout<<c<<" Largest number"<<endl;
        }
    }
    return 0;
}
