

#include<iostream>
#include<vector>
#include<climits>
using namespace std;

typedef long long ll;
// #define ll long long
vector<vector<ll>>dp;
ll fbu(vector<int>&wts,vector<int>&val,int tv,int W){
    dp.clear();
    dp.resize(101,vector<ll>(100001,INT_MAX));
    int n=wts.size();
    if(tv==0)return 0;
    for(int i=0;i<dp.size();i++){
        dp[i][0]=0;
    }
    for(int idx=n-1;idx>=0;idx--){
        for(int j=0;j<=tv;j++){
            ll ans=INT_MAX;
            ans=min(ans,dp[idx+1][j]);
            if(val[idx]<=j){
                ans=min(ans,dp[idx+1][j-val[idx]] + wts[idx]);
            }
            dp[idx][j]=ans;
        }
    }
    int result=-1;
    for(int i=0;i<=n*1000;i++){
        if(dp[0][i]<=W){
            result=i;
        }
    }
return result;
}
int main(){
    int n,W;
    cin>>n>>W;
    vector<int>wts(n),val(n);
    for(int i=0;i<n;i++){
        cin>>wts[i];
        cin>>val[i];
    }
    cout<<fbu(wts,val,n*1000,W);
    return 0;
}