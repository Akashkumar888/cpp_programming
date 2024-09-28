
#include<iostream>
#include<vector>
#include<climits>
using namespace std;

typedef long long ll;
// #define ll long long
vector<vector<ll>>dp;
ll f(vector<int>&wts,vector<int>&val,int idx,int tv){
    if(tv==0)return 0;
    if(idx==wts.size())return INT_MAX;
    if(dp[idx][tv]!=-1)return dp[idx][tv];
    ll ans=INT_MAX;
    ans=min(ans,f(wts,val,idx+1,tv));
    if(val[idx]<=tv){
        ans=min(ans,f(wts,val,idx+1,tv-val[idx]) + wts[idx]);
    }
    return dp[idx][tv]=ans;
}
int main(){
    int n,tv;
    cin>>n>>tv;
    vector<int>wts(n),val(n);
    dp.clear();
    dp.resize(101,vector<ll>(100001,-1));
    for(int i=0;i<n;i++){
        cin>>wts[i];
        cin>>val[i];
    }
    int ans=-1;
    for(int i=0;i<=n*1000;i++){
        if(f(wts,val,0,i)<=tv){
            ans=i;
        }
    }
    cout<<ans<<endl;
    return 0;
}