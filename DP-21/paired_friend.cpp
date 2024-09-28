
#include<iostream>
#include<vector>
using namespace std;
vector<int>dp;
int friendpair(int n){
if(n==1||n==2)return n;
if(dp[n]!=-1)return dp[n];
return dp[n]=friendpair(n-1)+(n-1)*friendpair(n-2);
}
int main(){
    int n;
    cin>>n;
    dp.clear();
    dp.resize(n+1,-1);
    cout<<friendpair(n);
    return 0;
}