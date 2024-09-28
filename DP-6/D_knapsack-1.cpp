
#include<iostream>
#include<vector>
#include<climits>
using namespace std;
// typedef long long ll;
#define ll long long
vector<vector<ll>>dp;
ll f(vector<int>&wts,vector<int>&val,int idx,int W){
if(idx>=wts.size()) return 0;
if(dp[idx][W]!=-1)return dp[idx][W];
ll ans=INT_MIN;
ans=max(ans,f(wts,val,idx+1,W));
if(wts[idx]<=W){
 ans=max(ans,f(wts,val,idx+1,W-wts[idx])+val[idx]);
}
return dp[idx][W]=ans;
}
int main()
{
    int n,W;
    cin>>n>>W;
    vector<int>wts(n),val(n);
    dp.clear();
    dp.resize(n+1,vector<ll>(W+1,-1));
    for(int i=0;i<n;i++){
        cin>>wts[i];
        cin>>val[i];
    }
     cout<<f(wts,val,0,W);
return 0;
}