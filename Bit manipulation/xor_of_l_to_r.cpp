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
    int l,r;
    cin>>l>>r;
    int k=f(l-1);
    int m=f(r);
    int final=k^m;
    cout<<final;
return 0;
}