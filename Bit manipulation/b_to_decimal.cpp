
#include<bits/stdc++.h>
using namespace std;
int f(string &s){
    int num=0;
    int n=s.size();
    for(int i=n-1;i>=0;i--){
        if(s[i]=='1')num+=pow(2,n-i-1);
        else continue;
        // num+=(1<<(n-i-1));
    }
    return num;
}
int main()
{
    string s;
    cin>>s;
    cout<<f(s);
return 0;
}