
class Solution {
  public:
//   You need to determine the maximum possible amount of money you can win if you go first.
// Note: Both the players are playing optimally. -> use DP
// when it's your turn
//do your best (max)
// when it's your opponent turn
// expect the worst from the result (min)
// min max game strategy
  int solve(int i,int j,vector<int>&arr,vector<vector<int>>&dp){
      if(i>j)return 0;
      if(i==j)return arr[i];// arr[j]
      if(dp[i][j]!=-1)return dp[i][j];
      // recurion for player 1
      int take_i=arr[i]+min(solve(i+2,j,arr,dp),solve(i+1,j-1,arr,dp));
      int take_j=arr[j]+min(solve(i+1,j-1,arr,dp),solve(i,j-2,arr,dp));
      return dp[i][j]=max(take_i,take_j);//the maximum possible amount of money you can win if you go first
  }
    int maximumAmount(vector<int> &arr) {
        // code here
        int n=arr.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return solve(0,n-1,arr,dp);
    }
};


// 👉 “How to convert the TOP-DOWN base cases into BOTTOM-UP base cases?”
// I will NOT rewrite your whole code.
// I will ONLY show the base-case conversion clearly.
// ✅ Your Top-Down Base Cases
// if (i > j) return 0;
// if (i == j) return arr[i];
// These correspond to:
// 1️⃣ Empty interval → dp[i][j] = 0
// 2️⃣ Single element → dp[i][i] = arr[i]
// And for j = i+1:
// 3️⃣ Two elements →
// dp[i][i+1] = max(arr[i], arr[i+1])
// (because choose the larger value)
// ✅ Bottom-Up Equivalent Base Cases
// In bottom-up, dp is a table, not recursion.
// So you initialize dp before filling bigger intervals.
// 👇 Exact conversion of your base cases:
// ✔ Base Case 1 → (i > j) → Already handled (loop won’t fill invalid i > j)
// We don’t store dp[i][j] for i > j.
// Bottom-up loops naturally skip those.
// ✔ Base Case 2 → (i == j) → single element
// for (int i = 0; i < n; i++)
//     dp[i][i] = arr[i];

// This matches:
// if (i == j) return arr[i];
// ✔ Base Case 3 → (j == i+1) → two elements
// for (int i = 0; i + 1 < n; i++)
//     dp[i][i+1] = max(arr[i], arr[i+1]);
// This corresponds to the recurrence:
// take_i = arr[i] + min(0, 0)
// take_j = arr[j] + min(0, 0)
// Choosing max(arr[i], arr[j]).
// ❓ “dp[i][i+1] = max(arr[i], arr[i+1]); where does this come from?”
// Let’s derive it directly from your recursion, step-by-step.
// ✅ Your recursion for reference
// int take_i = arr[i] + min(solve(i+2, j), solve(i+1, j-1));
// int take_j = arr[j] + min(solve(i+1, j-1), solve(i, j-2));
// dp[i][j] = max(take_i, take_j);
// Now let’s plug in the special case:
// ⭐ Case: j = i+1 (only TWO coins left)
// So interval is:
// [i, j] = [i, i+1]
// Coins:
// arr[i], arr[i+1]
// There is no third coin, so subproblems like i+2, j-2 become out of range.
// Step 1: Evaluate take_i
// If you take arr[i]:
// take_i = arr[i] + min( solve(i+2, i+1), solve(i+1, i) )
// Now check both calls:
// solve(i+2, i+1) → i+2 > i+1 → base case → returns 0
// solve(i+1, i) → i+1 > i → base case → returns 0
// So:
// take_i = arr[i] + min(0, 0)
// take_i = arr[i]
// Step 2: Evaluate take_j
// If you take arr[i+1]:
// take_j = arr[i+1] + min( solve(i+1, i), solve(i, i-1) )
// Both subcalls:
// solve(i+1, i) → returns 0
// solve(i, i-1) → returns 0
// So:
// take_j = arr[i+1] + min(0,0)
// take_j = arr[i+1]
// Step 3: Final answer for dp[i][i+1]
// Your recurrence says:
// dp[i][i+1] = max(take_i, take_j)
// Which becomes:
// dp[i][i+1] = max(arr[i], arr[i+1])
// 🎉 THAT’S where the base case comes from!
// It comes directly from:
// applying your recurrence
// plugging j = i+1
// watching subproblems return 0
// comparing the two coin values

// ✅ FINAL: Bottom-Up Base Case 3 (exact origin)
// // only two coins: pick the better one
// dp[i][i+1] = max(arr[i], arr[i+1]);


class Solution {
  public:
// You need to determine the maximum possible amount of money you can win if you go first.
// Note: Both the players are playing optimally. -> use DP
// when it's your turn
//do your best (max)
// when it's your opponent turn
// expect the worst from the result (min)
    int maximumAmount(vector<int> &arr) {
        // code here
        int n=arr.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        // base case: same index
        for (int i=0;i<n;i++) dp[i][i] = arr[i];
        // base case: two elements
        for (int i=0;i+1<n;i++)dp[i][i+1]=max(arr[i],arr[i+1]);
        // bottom-up in YOUR style:
        // i from n-1 → 0
        // j from i+2 → n-1
        for(int i=n-1;i>=0;i--){
            for(int j=i+2;j<n; j++){

                int left1=dp[i+2][j];     // solve(i+2, j)
                int left2=dp[i+1][j-1];   // solve(i+1, j-1)
                int take_i=arr[i]+min(left1,left2);

                int right1=dp[i+1][j-1];  // solve(i+1, j-1)
                int right2=dp[i][j-2];    // solve(i, j-2)
                int take_j=arr[j]+min(right1,right2);

                dp[i][j]=max(take_i, take_j);
            }
        }
        return dp[0][n-1];
    }
};



class Solution {
public:
//   You need to determine the maximum possible amount of money you can win if you go first.
// Note: Both the players are playing optimally. -> use DP
// when it's your turn
//do your best (max)
// when it's your opponent turn
// expect the worst from the result (min)
// min max game strategy
  int solve(int i,int j,vector<int>&nums,vector<vector<int>>&dp){
      if(i>j)return 0;
      if(i==j)return nums[i];// nums[j]
      if(dp[i][j]!=-1)return dp[i][j];
      // recurion for player 1
      int take_i=nums[i]+min(solve(i+2,j,nums,dp),solve(i+1,j-1,nums,dp));
      int take_j=nums[j]+min(solve(i+1,j-1,nums,dp),solve(i,j-2,nums,dp));
      return dp[i][j]=max(take_i,take_j);//the maximum possible amount of money you can win if you go first
  }
    bool predictTheWinner(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        int totalSum=accumulate(nums.begin(),nums.end(),0);
        int player1Sum=solve(0,n-1,nums,dp);
        int player2Sum=totalSum-player1Sum;
        return player1Sum>=player2Sum;
    }
};




class Solution {
public:

    int maximumAmount(vector<int> &arr) {
        int n = arr.size();

        vector<int> prev2(n,0), prev1(n,0), temp(n,0);

        // i = n-1 (base case)
        for(int j=0; j<n; j++)
            temp[j] = (j == n-1 ? arr[n-1] : 0);

        prev1 = temp;   // dp[i+1]

        // i = n-2 (base case)
        for(int j=0; j<n; j++) {
            if(j == n-2) temp[j] = arr[n-2];
            else if(j == n-1) temp[j] = max(arr[n-2], arr[n-1]);
            else temp[j] = 0;
        }

        prev2 = prev1;  // dp[i+2]
        prev1 = temp;   // dp[i+1]

        // i from n-3 → 0
        for(int i=n-3; i>=0; i--) {

            // dp[i][i]
            temp[i] = arr[i];

            // dp[i][i+1]
            temp[i+1] = max(arr[i], arr[i+1]);

            for(int j=i+2; j<n; j++) {

                int left1 = prev2[j];      // dp[i+2][j]
                int left2 = prev1[j-1];    // dp[i+1][j-1]
                int take_i = arr[i] + min(left1, left2);

                int right1 = prev1[j-1];   // dp[i+1][j-1]
                int right2 = temp[j-2];    // dp[i][j-2]
                int take_j = arr[j] + min(right1, right2);

                temp[j] = max(take_i, take_j);
            }

            prev2 = prev1;
            prev1 = temp;
        }

        return temp[n-1];
    }
};


class Solution {
public:
//   You need to determine the maximum possible amount of money you can win if you go first.
// Note: Both the players are playing optimally. -> use DP
// when it's your turn
//do your best (max)
// when it's your opponent turn
// expect the worst from the result (min)
// min max game strategy
    bool predictTheWinner(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        // base case: same index
        for (int i=0;i<n;i++) dp[i][i] = nums[i];
        // base case: two elements
        for (int i=0;i+1<n;i++)dp[i][i+1]=max(nums[i],nums[i+1]);
        // bottom-up in YOUR style:
        // i from n-1 → 0
        // j from i+2 → n-1
        for(int i=n-1;i>=0;i--){
            for(int j=i+2;j<n; j++){

                int left1=dp[i+2][j];     // solve(i+2, j)
                int left2=dp[i+1][j-1];   // solve(i+1, j-1)
                int take_i=nums[i]+min(left1,left2);

                int right1=dp[i+1][j-1];  // solve(i+1, j-1)
                int right2=dp[i][j-2];    // solve(i, j-2)
                int take_j=nums[j]+min(right1,right2);

                dp[i][j]=max(take_i, take_j);
            }
        }
        int player1Sum=dp[0][n-1];
        int totalSum=accumulate(nums.begin(),nums.end(),0);
        int player2Sum=totalSum-player1Sum;
        return player1Sum>=player2Sum;
    }
};

class Solution {
public:
//   You need to determine the maximum possible amount of money you can win if you go first.
// Note: Both the players are playing optimally. -> use DP
// when it's your turn
//do your best (max)
// when it's your opponent turn
// expect the worst from the result (min)
// min max game strategy
  int solve(int i,int j,vector<int>&nums,vector<vector<int>>&dp){
      if(i>j)return 0;
      if(dp[i][j]!=-1)return dp[i][j];
      // recurion for player 1
      int take_i=nums[i]+min(solve(i+2,j,nums,dp),solve(i+1,j-1,nums,dp));
      int take_j=nums[j]+min(solve(i+1,j-1,nums,dp),solve(i,j-2,nums,dp));
      return dp[i][j]=max(take_i,take_j);//the maximum possible amount of money you can win if you go first
  }
    bool predictTheWinner(vector<int>& nums) {
        int n=nums.size();
        vector<int> prev2(n,0), prev1(n,0), temp(n,0);

        // i = n-1 (base case)
        for(int j=0; j<n; j++)
            temp[j] = (j == n-1 ? nums[n-1] : 0);

        prev1 = temp;   // dp[i+1]

        // i = n-2 (base case)
        for(int j=0; j<n; j++) {
            if(j == n-2) temp[j] = nums[n-2];
            else if(j == n-1) temp[j] = max(nums[n-2], nums[n-1]);
            else temp[j] = 0;
        }

        prev2 = prev1;  // dp[i+2]
        prev1 = temp;   // dp[i+1]

        // i from n-3 → 0
        for(int i=n-3; i>=0; i--) {

            // dp[i][i]
            temp[i] = nums[i];

            // dp[i][i+1]
            temp[i+1] = max(nums[i], nums[i+1]);

            for(int j=i+2; j<n; j++) {

                int left1 = prev2[j];      // dp[i+2][j]
                int left2 = prev1[j-1];    // dp[i+1][j-1]
                int take_i = nums[i] + min(left1, left2);

                int right1 = prev1[j-1];   // dp[i+1][j-1]
                int right2 = temp[j-2];    // dp[i][j-2]
                int take_j = nums[j] + min(right1, right2);

                temp[j] = max(take_i, take_j);
            }

            prev2 = prev1;
            prev1 = temp;
        }

        int player1Sum=temp[n-1];
        int totalSum=accumulate(nums.begin(),nums.end(),0);
        int player2Sum=totalSum-player1Sum;
        return player1Sum>=player2Sum;
    }
};


class Solution {
public:
//   You need to determine the maximum possible amount of money you can win if you go first.
// Note: Both the players are playing optimally. -> use DP
// when it's your turn
//do your best (max)
// when it's your opponent turn
// expect the worst from the result (min)
// min max game strategy
// difference of player1 - player2
  int solve(int i,int j,vector<int>&nums,vector<vector<int>>&dp){
      if(i>j)return 0;
      if(i==j)return nums[i];// nums[j]
      if(dp[i][j]!=-1)return dp[i][j];
      // recurion for player 1
      int take_i=nums[i]-solve(i+1,j,nums,dp);
      int take_j=nums[j]-solve(i,j-1,nums,dp);
      return dp[i][j]=max(take_i,take_j);//the maximum possible amount of money you can win if you go first
  }
    bool predictTheWinner(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        int diffOfPlayer1AndPlayer2=solve(0,n-1,nums,dp);
        return diffOfPlayer1AndPlayer2 >=0;
    }
};

