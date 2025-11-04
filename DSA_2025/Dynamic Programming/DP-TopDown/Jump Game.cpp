
class Solution {
public:
// bool f(int i,int n,vector<int>&nums,vector<int>&dp){
//     if(i==n-1)return true;
//     if(i>=n)return false;
//     if(dp[i]!=-1)return dp[i];
//     for(int j=1;j<=nums[i];j++){
//         if(i+j<n){
//             if(f(i+j,n,nums,dp)==true)return dp[i]= true;
//         }
//     }
//     return dp[i]=false;
// }
    bool canJump(vector<int>& arr) {
        // int n=nums.size();
        // vector<int>dp(n,-1);
        // return f(0,n,nums,dp);
        int n=arr.size();
        if(n==1)return true;
       int maxStep=arr[0];
       int endStep=arr[0];
       int step=1;
       for(int i=1;i<n;i++){
           if(i>maxStep)return false;
           if(i==n-1)return true;
           maxStep=max(maxStep,i+arr[i]);
           if(i==endStep){
               step++;
               endStep=maxStep;
           }
       }
       return false;
    }
};

