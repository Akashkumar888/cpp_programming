
#include<iostream>
#include<vector>
using namespace std;

vector<int>dp; // global declaration 

int fib(int n){
    if(n==0||n==1)return n;
    if(dp[n]!=-1)return dp[n];
    return dp[n]=fib(n-1)+fib(n-2);
}
int main(){
    int n;
    cin>>n;
    dp.clear();
    dp.resize(n+1,-1);
    cout<<fib(n);
    return 0;
}