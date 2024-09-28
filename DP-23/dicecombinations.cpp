
#include<iostream>
#include<climits>
#include<vector>
using namespace std;
vector<int>dp;
int m=1e9+7;
int f(int sum){
    if(sum==0)return 1;
    if(dp[sum]!=-1)return dp[sum];
    int count=0;
    for(int i=1;i<=6;i++){
        if(sum-i<0)break;;
        count+=( f(sum-i))%m;
    }
    return dp[sum]=(count%m);
}
int main(){
    // 1-6
    int sum;
    cin>>sum;
    dp.clear();
    dp.resize(sum+1,-1);
    // vector<int>dice={1,2,3,4,5,6};
    cout<<f(sum);
 return 0;   
}
