
#include<iostream>
#include<climits>
#include<vector>
using namespace std;
vector<int>dp;
vector<int>getdigit(int n){
    vector<int>v;
    while(n!=0){
        if(n%10!=0){
            v.push_back(n%10);
        }
        n=n/10;
    }
    return v;
}
int f(int n){
    if(n==0)return 0;
    if(n<=9)return 1;
    if(dp[n]!=-1)return dp[n];
    vector<int>digit=getdigit(n);
    int ans=INT_MAX;
    for(int i=0;i<digit.size();i++){
        ans = min(f(n-digit[i]),ans);
    }
    return dp[n]=1+ans;
}
int main(){
    int n;
    cin>>n;
    dp.clear();
    dp.resize(n+1,-1);
    cout<<f(n)<<endl;
    return 0;
}
