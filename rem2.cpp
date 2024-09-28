#include<iostream>
using namespace std;
int main(){
    int a,b;
    cin>>a>>b;
    int q=a/b;
    int r=a-(b*q);
    cout<<"remainder = "<<r<<endl;
}