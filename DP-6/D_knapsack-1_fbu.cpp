

#include<iostream>
#include<vector>
#include<climits>
using namespace std;
// typedef long long ll;
#define ll long long
vector<vector<ll>>dp;
ll fbu(vector<int>&wts,vector<int>&val,int W){
   int n=wts.size();
   dp.clear();
    dp.resize(n+1,vector<ll>(W+1,0)); 
    for(int idx=n-1;idx>=0;idx--){
        for(int j=0;j<=W;j++){
            ll ans=INT_MIN;
            ans=max(ans,dp[idx+1][j]);
            if(wts[idx]<=j){
                ans=max(ans,val[idx]+dp[idx+1][j-wts[idx]]);
            }
            dp[idx][j]=ans;
        }
    }
    return dp[0][W];
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
    cout<<fbu(wts,val,W);
return 0;
}