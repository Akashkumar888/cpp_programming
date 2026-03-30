
class Solution {
  public:
  int solve(int i,vector<int>&arr,int target,vector<vector<int>>&dp){
      // Correct base cases
      if(i == 0) { // 1 ≤ arr.size() ≤ 10^3 , 0 ≤ arr[i] ≤ 10^3 , 0 ≤ target ≤ 10^3
            if(target == 0 && arr[0] == 0) return 2;  // {} and {0}
            if(target == 0) return 1;                 // empty subset
            if(arr[0] == target) return 1;           // single element subset
            return 0;
      }
      if(dp[i][target]!=-1)return dp[i][target];
      int notpick=solve(i-1,arr,target,dp);
      int pick=0;
      if(arr[i]<=target)pick=solve(i-1,arr,target-arr[i],dp);
      return dp[i][target]=pick + notpick;
  }
    int countPartitions(vector<int>& arr, int diff) {
        // Code here
        // s1-s2=diff
        // s1>=s2
        // s1-s2=diff; equations 1
        // s1=totalSum-s2; put this value in equations 1
        // totalSum-s2-s2=diff;
        // s2=(totalSum-diff)/2;
        // it should be +ve and even also 
        int n=arr.size();
        int totalSum=accumulate(arr.begin(),arr.end(),0);
        if((totalSum-diff)<0 || (totalSum-diff)%2)return 0;// if totalSum is odd 
        int sum=(totalSum-diff)/2;
        vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        return solve(n-1,arr,sum,dp);
    }
};

class Solution {
  public:
    int countPartitions(vector<int>& arr, int diff) {
        // Code here
        // s1-s2=diff
        // s1>=s2
        // s1-s2=diff; equations 1
        // s1=totalSum-s2; put this value in equations 1
        // totalSum-s2-s2=diff;
        // s2=(totalSum-diff)/2;
        // it should be +ve and even also 
        int n=arr.size();
        int totalSum=accumulate(arr.begin(),arr.end(),0);
        if((totalSum-diff)<0 || (totalSum-diff)%2)return 0;// if totalSum is odd 
        int sum=(totalSum-diff)/2;
        vector<vector<int>>dp(n,vector<int>(sum + 1, 0));
        // ---- Base Case for i = 0 (only nums[0] available) ----
        // because this array contains 0 elements also
        // 1 ≤ arr.size() ≤ 10^3 , 0 ≤ arr[i] ≤ 10^3 , 0 ≤ target ≤ 10^3
        for (int target = 0; target <= sum; target++) {
            if (target == 0 && arr[0] == 0)dp[0][target] = 2;     // {} and {0}
            else if (target == 0)dp[0][target] = 1;     // empty subset {}
            else if (arr[0] == target)dp[0][target] = 1;     // single element subset
            else dp[0][target] = 0;
        }
        for(int i=1;i<n;i++){
            for(int target=0;target<=sum;target++){// because this array contains 0 elements also
              // 1 ≤ arr.size() ≤ 10^3 , 0 ≤ arr[i] ≤ 10^3 , 0 ≤ target ≤ 10^3
                int notpick=dp[i-1][target];
                int pick=0;
                if(arr[i]<=target)pick=dp[i-1][target-arr[i]];
                dp[i][target]=pick + notpick;
            }
        }
        return dp[n-1][sum];
    }
};

class Solution {
  public:
    int countPartitions(vector<int>& arr, int diff) {
        // Code here
        // s1-s2=diff
        // s1>=s2
        // s1-s2=diff; equations 1
        // s1=totalSum-s2; put this value in equations 1
        // totalSum-s2-s2=diff;
        // s2=(totalSum-diff)/2;
        // it should be +ve and even also 
        int n=arr.size();
        int totalSum=accumulate(arr.begin(),arr.end(),0);
        if((totalSum-diff)<0 || (totalSum-diff)%2)return 0;// if totalSum is odd 
        int sum=(totalSum-diff)/2;
        // dp[i][target] = number of ways to make target using first i elements
        vector<int>prev(sum+1,0),temp(sum+1,0);
        // ---- Base Case for i = 0 (only nums[0] available) ----
        // because this array contains 0 elements also
        for (int target = 0; target <= sum; target++) {
            if (target == 0 && arr[0] == 0)prev[target] = 2;     // {} and {0}
            else if (target == 0)prev[target] = 1;     // empty subset {}
            else if (arr[0] == target)prev[target] = 1;     // single element subset
            else prev[target] = 0;
        }
        for(int i=1;i<n;i++){
            for(int target=0;target<=sum;target++){// because this array contains 0 elements also
                int notpick=prev[target];
                int pick=0;
                if(arr[i]<=target)pick=prev[target-arr[i]];
                temp[target]=pick + notpick;
            }
            prev=temp;
        }
        return prev[sum];
    }
};

// We are given:
// s1 - s2 = diff
// s1 + s2 = totalSum
// 🔥 Solve Equations
// Add both:
// 2*s1 = totalSum + diff
// s1 = (totalSum + diff) / 2
// OR subtract:
// 2*s2 = totalSum - diff
// s2 = (totalSum - diff) / 2
// ❓ So which one to use?
// 👉 You can use either s1 OR s2
// But in coding:
// We usually use s2 = (totalSum - diff) / 2
// 💡 Why prefer s2?
// Because:
// Subset sum problem → find subset with given sum
// 👉 Smaller target is better
// s2 ≤ s1 always
// So:
// Use s2 → less DP states → efficient
// ⚠️ Important Condition
// if ((totalSum - diff) < 0 || (totalSum - diff) % 2 != 0)return 0;
// 👉 Otherwise no solution

class Solution {
  public:
  // top-down code
  int solve(int i,vector<int>&arr,int tr,vector<vector<int>>&dp){
      if(i==0){
          if(tr== 0 && arr[0]==0)return 2;
          if(tr==0 || tr==arr[0])return 1;
          return 0;
      }
      if(dp[i][tr]!=-1)return dp[i][tr];
      int pick=0;
      int notpick=solve(i-1,arr,tr,dp);
      if(arr[i]<=tr)pick=solve(i-1,arr,tr-arr[i],dp);
      return dp[i][tr]=pick+notpick;
  }
    int countPartitions(vector<int>& arr, int diff) {
        // Code here
        int n=arr.size();
        int totalSum=0;
        for(int &num:arr)totalSum+=num;
        // s1-s2=diff
        // s1+s2=totalSum
        // totalSum-s2-s2=diff
        // s2=(totalSum-diff)/2
        if((totalSum-diff)<0 || (totalSum-diff)%2!=0)return 0;
        int s2=(totalSum-diff)/2;
        vector<vector<int>>dp(n,vector<int>(s2+1,-1));
        return solve(n-1,arr,s2,dp);
    }
};


class Solution {
  public:
  // bottom-up code
    int countPartitions(vector<int>& arr, int diff) {
        // Code here
        int n=arr.size();
        int totalSum=0;
        for(int &num:arr)totalSum+=num;
        // s1-s2=diff
        // s1+s2=totalSum
        // totalSum-s2-s2=diff
        // s2=(totalSum-diff)/2
        if((totalSum-diff)<0 || (totalSum-diff)%2!=0)return 0;
        int s2=(totalSum-diff)/2;
        vector<vector<int>>dp(n,vector<int>(s2+1,0));
        
        // base case
        for(int tr=0;tr<=s2;tr++){
            if(tr == 0 && arr[0] == 0)dp[0][tr]=2;   
            else if(tr==0 || arr[0]==tr)dp[0][tr]=1;
            else dp[0][tr]=0;
        }
        for(int i=1;i<n;i++){
            for(int tr=0;tr<=s2;tr++){
                int pick=0;
                int notpick=dp[i-1][tr];
                if(arr[i]<=tr)pick=dp[i-1][tr-arr[i]];
                dp[i][tr]=pick+notpick;
            }
        }
        return dp[n-1][s2];
    }
};



class Solution {
  public:
  // bottom-up code space optimised
    int countPartitions(vector<int>& arr, int diff) {
        // Code here
        int n=arr.size();
        int totalSum=0;
        for(int &num:arr)totalSum+=num;
        // s1-s2=diff
        // s1+s2=totalSum
        // totalSum-s2-s2=diff
        // s2=(totalSum-diff)/2
        if((totalSum-diff)<0 || (totalSum-diff)%2!=0)return 0;
        int s2=(totalSum-diff)/2;
        vector<int>prev(s2+1,0);
        vector<int>curr(s2+1,0);
        // base case
        for(int tr=0;tr<=s2;tr++){
            if(tr == 0 && arr[0] == 0)prev[tr]=2;   
            else if(tr==0 || arr[0]==tr)prev[tr]=1;
            else prev[tr]=0;
        }
        for(int i=1;i<n;i++){
            for(int tr=0;tr<=s2;tr++){
                int pick=0;
                int notpick=prev[tr];
                if(arr[i]<=tr)pick=prev[tr-arr[i]];
                curr[tr]=pick+notpick;
            }
            prev=curr;
        }
        return prev[s2];
    }
};
