
#include<bits/stdc++.h>
using namespace std;
int main(){
  
  int n,k;
  cin>>n>>k;
  vector<int>arr(n);
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  vector<int>dp(n+1);
  dp[0]=0;
  for(int i=1;i<n;i++){
  int step=INT_MAX;
  for(int j=1;j<=k;j++){
    if(i-j>=0){
      int jump= dp[i-j] + abs(arr[i]-arr[i-j]);
      step=min(step,jump);
    }
  }
  dp[i]=step;
  }
  cout<<dp[n-1]<<endl;
  return 0;
}