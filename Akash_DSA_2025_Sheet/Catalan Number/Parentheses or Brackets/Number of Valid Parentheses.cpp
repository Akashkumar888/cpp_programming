
// Classic DP Approach (Universal)
// Use DP with recurrence:

// C(0) = 1
// C(n) = Σ C(i) * C(n-1-i)  for i = 0 … n-1


// This works in O(n²):
// long long catalanDP(int n) {
//     vector<long long> C(n+1,0);
//     C[0] = 1;  // base

//     for (int i = 1; i <= n; i++) {
//         for (int j = 0; j < i; j++) {
//             C[i] += C[j] * C[i - 1 - j];
//         }
//     }
//     return C[n];
// }


// Use it like:
// int pairs = n/2;      // if input is length (e.g., n=6 → 3 pairs)
// cout << catalanDP(pairs);

// Efficient Direct Formula (O(n))

// This uses a safe multiplication formula to avoid overflow:

// long long catalanFormula(int n) {
//     long long res = 1;
//     for (int i = 0; i < n; i++) {
//         res = res * 2 * (2*i + 1) / (i + 2);
//     }
//     return res;
// }


// This calculates the nth Catalan number using:
// C(n) = (1 / (n+1)) * (2n choose n)


// without factorials.
// 🧠 When to Use Catalan Numbers
// Catalan numbers come up in many classic problems such as:
// Counting valid parentheses combinations (length = 2×n)
// Unique Binary Search Trees (LeetCode 96)
// Generate Parentheses (LeetCode 22)
// Count ways to tile problems, polygon triangulations, etc.
// You can find examples on GeeksforGeeks Catalan coding problems page here:
// 👉 https://www.geeksforgeeks.org/dsa/catalan-coding-problems/


// 🥉 Recursive + Memo  Slightly slower due to recursion overhead, Risk of stack issues for larger k
class Solution {
public:
    long long catalanRec(int k,vector<long long>&dp){
        if(k == 0 || k == 1) return 1;
        if(dp[k] != -1) return dp[k];

        long long ans = 0;
        for(int i = 0; i < k; i++){
            ans += catalanRec(i,dp) * catalanRec(k - 1 - i,dp);
        }
        return dp[k] = ans;
    }

    int findWays(int n) {
        if(n % 2) return 0;        // odd length → impossible
        int k = n / 2;
        vector<long long>dp(k+1,-1);
        return catalanRec(k,dp);
    }
};

// 🥇 Best & Universal (Use Everywhere)
// C(0) = 1
// C(n) = Σ C(i) * C(n-1-i)   for i = 0 … n-1
// Using this, the Catalan series becomes:

// n	C(n)
// 0	1
// 1	1
// 2	2
// 3	5
// 4	14
// 5	42
// 6	132
// 7	429
// 8	1430
// 🥇 Best & Universal (Use Everywhere)
class Solution {
public:
    long long catalanRec(int k){
        vector<long long> C(k + 1, 0);
        C[0] = C[1] = 1;
        for(int i = 2; i <= k; i++){
            for(int j = 0; j < i; j++){
                C[i] += C[j] * C[i - 1 - j];
            }
        }
        return C[k];
    }
    int findWays(int n) {
        if(n % 2) return 0;        // odd length → impossible
        int k=n/2;
        return catalanRec(k);
    }
};


// 🥈 Formula Method (Fast but Risky for Large k)
class Solution {
public:
    long long catalanRec(int k){
        long long res = 1;
        for (int i = 0; i < k; i++) {
            res = res * 2 * (2*i + 1) / (i + 2);
        }
        return res;
    }
    int findWays(int n) {
        if(n % 2) return 0;        // odd length → impossible
        int k=n/2;
        return catalanRec(k);
    }
};


// Example problems based on Catalan Number

// Nth Catalan Number
// Make Catalan Sequence
// Count all Possible BST
// Print all Possible BST
// Binary Trees with given Inorder Traversal
// BSTs using Array Elements
// Valid Parentheses
// Distinct Regular Bracket Sequences
// Counting Polygon Triangulation
// Succinct Encoding of Binary Tree
// Dyck Path
// Dyck Words of given length
// Non-crossing lines to connect points
// Binary Trees for given Preorder Sequence length
// Permutations no Three Increasing Subsequence
// Possible Permutations of given Array
// Paths from top Left to Bottom Right
// Sequences having non-negative Prefix Sums