
// recursion -> dp array -> variable prev2 , prev1 
class Solution {
  public:
  int solve(int i,vector<int>&height,vector<int>&dp){
      if(i==0)return 0;
      if(dp[i]!=-1)return dp[i];
      int twoStep=INT_MAX;
      int oneStep=abs(height[i]-height[i-1]) + solve(i-1,height,dp);
      if(i>=2) twoStep=abs(height[i]-height[i-2]) + solve(i-2,height,dp);
      return dp[i]=min(oneStep,twoStep);
  }
    int minCost(vector<int>& height) {
        // Code here
        int n=height.size();
        vector<int>dp(n+1,-1);
        return solve(n-1,height,dp);
    }
};

class Solution {
  public:
    int minCost(vector<int>& height) {
        // Code here
        int n=height.size();
        if(n<=1)return 0;
        vector<int>dp(n,0);
        dp[0]=0;// oneStep
        for(int i=1;i<n;i++){
          int twoStep=INT_MAX;
          int oneStep=abs(height[i]-height[i-1]) + dp[i-1];
          if(i>=2)twoStep=abs(height[i]-height[i-2]) + dp[i-2];
          dp[i]=min(oneStep,twoStep);
        }
        return dp[n-1]; // here it is array index i can't modify my own 
    }
};

class Solution {
  public:
    int minCost(vector<int>& height) {
        // Code here
        int n=height.size();
        if(n<=1)return 0;
        vector<int>dp(n,0);
        dp[0]=0;
        dp[1]=abs(height[1]-height[0]);
        for(int i=2;i<n;i++){
          int twoStep=INT_MAX;
          int oneStep=abs(height[i]-height[i-1]) + dp[i-1];
          if(i>=2)twoStep=abs(height[i]-height[i-2]) + dp[i-2];
          dp[i]=min(oneStep,twoStep);
        }
        return dp[n-1]; // here it is array index i can't modify my own 
    }
};

class Solution {
  public:
    int minCost(vector<int>& height) {
        // Code here
        int n=height.size();
        if(n<=1)return 0;
        int prev2=0;// oneStep
        int prev1=0;//twoStep
        for(int i=1;i<n;i++){
          int twoStep=INT_MAX;
          int oneStep=abs(height[i]-height[i-1]) + prev1;
          if(i>=2)twoStep=abs(height[i]-height[i-2]) + prev2;
          int curr=min(oneStep,twoStep);
          prev2=prev1;
          prev1=curr;
        }
        return prev1; // here it is array index i can't modify my own 
    }
};

class Solution {
  public:
    int minCost(vector<int>& height) {
        // Code here
        int n=height.size();
        if(n<=1)return 0;
        int prev2=0;// oneStep
        int prev1=abs(height[1]-height[0]);//twoStep
        for(int i=2;i<n;i++){
          int twoStep=INT_MAX;
          int oneStep=abs(height[i]-height[i-1]) + prev1;
          if(i>=2)twoStep=abs(height[i]-height[i-2]) + prev2;
          int curr=min(oneStep,twoStep);
          prev2=prev1;
          prev1=curr;
        }
        return prev1; // here it is array index i can't modify my own 
    }
};


class Solution {
  public:
    int minCost(vector<int>& height) {
        // Code here
        int n=height.size();
        if(n<=1)return 0;
        int prev2=0;// oneStep
        int prev1=0;//twoStep
        for(int i=1;i<n;i++){
          int twoStep=INT_MAX;
          int oneStep=abs(height[i]-height[i-1]) + prev1;
          if(i>=2)twoStep=abs(height[i]-height[i-2]) + prev2;
          prev2=prev1;
          prev1=min(oneStep,twoStep);
        }
        return prev1; // here it is array index i can't modify my own 
    }
};


class Solution {
  public:
    int minCost(vector<int>& height) {
        // Code here
        int n=height.size();
        if(n<=1)return 0;
        int prev2=0;// oneStep
        int prev1=abs(height[1]-height[0]);//twoStep
        for(int i=2;i<n;i++){
          int twoStep=INT_MAX;
          int oneStep=abs(height[i]-height[i-1]) + prev1;
          if(i>=2)twoStep=abs(height[i]-height[i-2]) + prev2;
          prev2=prev1;
          prev1=min(oneStep,twoStep);
        }
        return prev1; // here it is array index i can't modify my own 
    }
};

