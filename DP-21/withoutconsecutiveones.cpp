
#include<iostream>
#include<vector>
using namespace std;
vector<int>dp;
int fib(int n){
    if(n==1)return 2;
    if(n==2)return 3;
    if(dp[n]!=-1)return dp[n];
    return dp[n]=fib(n-1)+fib(n-2);
}
int main(){
    int n;
    cin>>n;
    dp.clear();
    dp.resize(n+1,-1);
    cout<<fib(n)<<endl;
    return 0;
}