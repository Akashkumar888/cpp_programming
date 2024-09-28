
#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
vector<int>dp;

vector<int>h; // global declaration 
int k;
int f(int i){
if(i>=h.size())return INT_MAX;
if(i==h.size()-1)return 0;
if(dp[i]!=-1)return dp[i];
int ans=INT_MAX;
for(int j=1;j<=k;j++){
if(i+j>=h.size())break;
ans=min(ans,abs(h[i]-h[i+j])+f(i+j));
}
return dp[i]=ans;
}
int main(){
    int n;
    cin>>n>>k;
    h.resize(n);
    dp.clear();
    dp.resize(n+1,-1);
    for(int i=0;i<n;i++)cin>>h[i];
    cout<<f(0)<<endl;
    return 0;
}
