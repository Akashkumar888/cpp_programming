#include<iostream>
using namespace std;
int main(){
    int a,b,c;
    cout<<"Enter 1st side :";
    cin>>a;
    cout<<"Enter 2nd side :";
    cin>>b;
    cout<<"Enter 3rd side :";
    cin>>c;
    if((a<b+c) && (b<a+c) && (c<a+b)){
        cout<<a<<" "<<b<<" "<<c<<" "<<" is a side of Triangle"<<endl;
    }
    
    else{
        cout<<" Not Triangle"<<endl;
    }
    return 0;
}