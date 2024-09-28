
#include<iostream>
#include<climits>
#include<vector>
using namespace std;
vector<int>dp;
int f(int sum,vector<int>&arr){
if(sum==0)return 0;
if(dp[sum]!=-1)return dp[sum];
int ans=INT_MAX;
for(int i=0;i<arr.size();i++){
    if(sum-arr[i]<0)continue;
    ans=min((f(sum-arr[i],arr)) ,ans);
}
return dp[sum]=1+ans;
}
int main(){
    int n,sum;
    cin>>n>>sum;
    vector<int>arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];
    dp.clear();
    dp.resize(sum+1,-1);

   int result=f(sum,arr);
   if(result==INT_MAX)cout<<-1;
   else cout<<result<<endl;
}
