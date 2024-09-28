#include<iostream>
using namespace std;
int main(){
    int a,b,c;
    cout<<"Enter the marks 1:";
    cin>>a;
    cout<<"Enter the marks 2:";
    cin>>b;
    cout<<"Enter the marks 3:";
    cin>>c;
    if(a<b){
        if(a<c){
            cout<<"Less marks :"<<a<<endl;
        }
        else{
            cout<<"Less marks :"<<c<<endl;
        }
    }
     else if(b<c){
        if(b<a){
            cout<<"Less marks :"<<b<<endl;
        }
        else{
            cout<<"Less marks :"<<a<<endl;
        }
    }
    else{
        if(c<b){
            cout<<"Less marks :"<<c<<endl;
        }
        else{
            cout<<"Less marks :"<<b<<endl;
        }
    }
    return 0;
}