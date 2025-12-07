
// Number of Structurally Different Binary Trees
// 1. Unlabeled Binary Trees (Only Structure Matters)
// The number of structurally different binary trees with n unlabeled nodes is given by the nth Catalan number:
// Cn​=n+11​(n2n​)
// Explanation:
// This counts all unique binary tree shapes, ignoring node values.
// Example:
// For n=3:
// C3​=5
// So, there are 5 unique binary tree structures.

// 2. Labeled Binary Trees (Structure + Node Labels)
// If each of the 
// n nodes has a distinct label, then every structural tree can be labeled in n! ways.
// Formula:
// Number of labeled trees=n!×Cn​
// Substituting the Catalan number: n!×n+11​(n2n​)
// This simplifies to:(n+1)!(2n)!​
// Explanation:
// First choose the structure (Catalan number).
// Then permute the 𝑛
// n labels in n! possible ways.
// Example:
// For n=3:
// (2*nCn)/n+1 formula for unique binary search tree possible.
// So, there are 30 different labeled binary trees.

// Catalan Number — Definition
// The nth Catalan number counts the number of ways to form various combinatorial structures, such as:
// Structurally unique Binary Trees
// Valid Parentheses strings
// Number of BSTs with 
// n keys
// Ways to triangulate a polygon
// Ways to partition expressions
// Mountain ranges, lattice paths, etc.
// Recursive Formula
// 𝐶𝑛=∑𝑖=0𝑛−1𝐶𝑖⋅𝐶𝑛−𝑖−1

// int factorial(int n,vector<int>&fact){
//     if(n==0)return 1;
//     if(fact[n]!=-1)return fact[n];
//     return fact[n]=n*factorial(n-1,fact);
// }
// int ncr(int n,int r){
// vector<int>fact(n,-1);
//     return (factorial(n,fact)/(factorial(n-r,fact)*factorial(r,fact)));
// }

class Solution {
public:
    /*
        Catalan Recurrence:
        C[n] = Σ ( C[i] * C[n-i-1] )   for i = 0 to n-1
        Base cases:
        C[0] = 1, C[1] = 1
    */
    int solve(int n,vector<int>&dp) {
        if(n <= 1)return 1;       // Base cases
        if(dp[n]!=-1)return dp[n];
        long long sum=0;
        for(int i=0;i<n;i++){
            sum +=solve(i, dp)*solve(n-i-1,dp);
        }
        return dp[n]=sum;
    }
    int numTrees(int n) {
        vector<int>dp(n+1,-1);
        return solve(n,dp);
    }
};


// int factorial(int n,vector<int>&fact){
//     if(n==0)return 1;
//     if(fact[n]!=-1)return fact[n];
//     return fact[n]=n*factorial(n-1,fact);
// }
// int ncr(int n,int r){
// vector<int>fact(n,-1);
//     return (factorial(n,fact)/(factorial(n-r,fact)*factorial(r,fact)));
// }

class Solution {
public:
    /*
        Catalan Recurrence:
        C[n] = Σ ( C[i] * C[n-i-1] )   for i = 0 to n-1
        Base cases:
        C[0] = 1, C[1] = 1
    */
    int numTrees(int n) {
        vector<int>dp(n+1,0);
        if(n<=1)return 1;
        dp[0]=1;
        dp[1]=1;
        for(int j=2;j<=n;j++){
        long long sum=0;
        for(int i=0;i<j;i++){
            sum +=dp[i]*dp[j-i-1];
        }
        dp[j]=sum;
        }
        return dp[n];
    }
};