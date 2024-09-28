#include<iostream>
using namespace std;
int main(){
    float x;
    cin>>x;
    float y=(int)x;
    if(y<0) y=y-1;
    float z=(float)y;
    x=x-z;
    cout<<x;
}