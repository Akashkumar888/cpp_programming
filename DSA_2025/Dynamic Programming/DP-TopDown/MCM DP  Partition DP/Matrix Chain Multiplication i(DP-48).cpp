

// i to j hai uske bich me k la kr jao
// i to k and k+1 to j 
// (arr[i-1]*arr[k]*arr[j])+solve(i,k,arr,dp)+solve(k+1,j,arr,dp);
// 4 types of base case in partition on dp 
// 1. base case i==j return 0;
// 2. base case i>=j return 0;
// 3. i==j return some value;
// 4. i>j return 0;


// 🔹 Base Cases (Partition DP – 4 types)
// You already wrote them perfectly, just clarifying 👇
// 1️⃣ i == j → only one matrix, no multiplication
// return 0;
// 2️⃣ i > j → invalid range
// return 0;
// 3️⃣ i == j but return some value
// ➡ used in problems like burst balloons, min score triangulation, etc.
// 4️⃣ i >= j → combined safe base case
// if(i >= j) return 0;
// 👉 In MCM we use: i == j → 0


// 🔹 WHY base case matters so much
// Partition DP recursively shrinks ranges.
// At some point, the range becomes:
// empty
// single element
// invalid
// If base case is wrong → WA / TLE / infinite recursion
// 🔹 The 4 Base-Case Types (Master Table)
// Case	Condition	Meaning	Return
// 1️⃣	i == j	Single item	0 (or value)
// 2️⃣	i > j	Invalid / empty	0
// 3️⃣	i == j	Single item but has value	arr[i], 1, etc
// 4️⃣	i >= j	Combined safe case	0
// 🔥 How to choose the correct base case?
// Ask ONE question 👇
// “When no partition is possible, what should the answer be?”


// ✅ TYPE 1: MCM (Matrix Chain Multiplication)
// Meaning
// One matrix → no multiplication needed
// Base Case
// if(i == j) return 0;
// Why NOT i > j?
// Because we never call such state in correct MCM recursion.
// ✅ TYPE 2: Burst Balloons
// Problem nature
// Single balloon → popping it gives coins
// Base Case
// if(i > j) return 0;
// Why?
// When all balloons are burst, range becomes empty.
// nums[i-1] * nums[k] * nums[j+1]
// Empty range → no coins → 0
// ✅ TYPE 3: Min Score Triangulation
// Meaning
// Triangle needs 3 points
// Less than 3 → no triangle possible
// Base Case
// if(j - i < 2) return 0;
// Which covers:
// i == j
// i + 1 == j
// ✅ TYPE 4: Boolean Parenthesization
// Meaning
// Single symbol (T / F) is already an answer
// Base Case
// if(i == j) {
//     if(isTrue) return s[i] == 'T';
//     else return s[i] == 'F';
// }
// Here i == j returns 1 or 0, not always zero.
// 🧠 Universal Decision Tree (EXAM GOLD)
// When you see solve(i, j):
// Step 1️⃣ Ask:
// “Can i == j be a valid answer?”
// ❌ No → return 0
// ✅ Yes → return value
// Step 2️⃣ Ask:
// “Does empty range make sense?”
// ❌ No → never call it
// ✅ Yes → if(i > j) return 0
// Step 3️⃣ Ask:
// “Is minimum size > 1?”
// Example:
// Triangulation → need 3 nodes
// Palindrome partition → length ≥ 1
// Then:
// if(j - i + 1 < required) return 0;
// 🔹 Visual Memory Trick 🧠
// Partition DP always looks like:
// i -------- k -------- j
// |---- left ----|---- right ----|

// When range collapses:
// same point → i == j
// crossed → i > j
// Your base case handles this collapse.
// 🧩 Template for ALL Partition DP Problems
// int solve(int i, int j) {
//     // BASE CASE (decide carefully)
//     if(i >= j) return 0;   // or value-based
//     int ans = INF;
//     for(int k = i; k < j; k++) {
//         ans = min(ans,
//             solve(i, k) +
//             solve(k+1, j) +
//             cost(i, k, j)
//         );
//     }
//     return ans;
// }
// 🎯 Final One-Line Rule (Tattoo-worthy)
// Partition DP = “When range cannot be partitioned anymore, return the cost of doing nothing.”
// Sometimes “doing nothing” costs:
// 0 → MCM, Burst Balloons
// 1 / value → Boolean DP
// arr[i] → leaf-based DP


class Solution {
  public:
  int solve(int i,int j,vector<int>&arr,vector<vector<int>>&dp){
      if(i==j)return 0;
      if(dp[i][j]!=-1)return dp[i][j];
      int leastNumber=INT_MAX;
      for(int k=i;k<=j-1;k++){
         int step=(arr[i-1]*arr[k]*arr[j])+solve(i,k,arr,dp)+solve(k+1,j,arr,dp);
         leastNumber=min(leastNumber,step);
      }
    return dp[i][j]=leastNumber;  
  }
    int matrixMultiplication(vector<int> &arr) {
        // code here
        int n=arr.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solve(1,n-1,arr,dp);
    }
};


class Solution {
  public:
  int solve(int i,int j,vector<int>&arr,vector<vector<int>>&dp){
      if(i==j)return 0;
      if(dp[i][j]!=-1)return dp[i][j];
      int leastNumber=INT_MAX;
      for(int k=i;k<j;k++){
         int step=(arr[i-1]*arr[k]*arr[j])+solve(i,k,arr,dp)+solve(k+1,j,arr,dp);
         leastNumber=min(leastNumber,step);
      }
    return dp[i][j]=leastNumber;  
  }
    int matrixMultiplication(vector<int> &arr) {
        // code here
        int n=arr.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return solve(1,n-1,arr,dp);
    }
};


class Solution {
  public:
    int matrixMultiplication(vector<int> &arr) {
        // code here
        int n=arr.size();
        vector<vector<int>>dp(n,vector<int>(n,INT_MAX));
        for(int i=1;i<n;i++)dp[i][i]=0;
        for(int i=n-1;i>=1;i--){// 🔹 i goes backward so that smaller ranges are solved first
            for(int j=i+1;j<n;j++){ // j start from i+1 because j always right of i that why not start from 0 
              // j always lies to the RIGHT of i
                int leastNumber=INT_MAX;
              for(int k=i;k<j;k++){
                 int step=(arr[i-1]*arr[k]*arr[j])+dp[i][k]+dp[k+1][j];
                 leastNumber=min(leastNumber,step);
              }
                 dp[i][j]=leastNumber; 
            }
        }
        return dp[1][n-1];
    }
};

class Solution {
  public:
    int matrixMultiplication(vector<int> &arr) {
        // code here
        int n=arr.size();
        vector<vector<int>>dp(n,vector<int>(n,INT_MAX));
        for(int i=1;i<n;i++)dp[i][i]=0;
        for(int i=n-1;i>=1;i--){
            for(int j=i+1;j<n;j++){
                int leastNumber=INT_MAX;
              for(int k=i;k<=j-1;k++){
                 int step=(arr[i-1]*arr[k]*arr[j])+dp[i][k]+dp[k+1][j];
                 leastNumber=min(leastNumber,step);
              }
                 dp[i][j]=leastNumber; 
            }
        }
        return dp[1][n-1];
    }
};
