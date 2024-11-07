#include<iostream>
using namespace std;
int f(int n){
    if(n%4==1)return 1;
    else if(n%4==2)return n+1;
    else if(n%4==3)return 0;
    else if(n%4==0)return n;
}
int main()
{
    int n;
    cin>>n;
    cout<<f(n);
return 0;
}