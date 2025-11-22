class Solution {
public:
    // prefix sum: sum of stones[i..j]
    int getSum(vector<int>& pre, int i, int j) {
        return pre[j + 1] - pre[i];
    }

    int solve(int i, int j, int K, vector<int>& pre, vector<vector<int>>& dp) {
        if (i == j) return 0;                 // only 1 pile → no cost
        if (dp[i][j] != -1) return dp[i][j];

        int ans = INT_MAX;

        // Try splitting at every (K-1) interval
        for (int mid = i; mid < j; mid += (K - 1)) {
            int left  = solve(i, mid, K, pre, dp);
            int right = solve(mid + 1, j, K, pre, dp);

            ans = min(ans, left + right);
        }

        // If this interval can merge into 1 pile, add sum
        if ((j - i) % (K - 1) == 0) {
            ans += getSum(pre, i, j);
        }

        return dp[i][j] = ans;
    }

    int mergeStones(vector<int>& stones, int K) {
        int n = stones.size();

        // If final merge to 1 pile is impossible
        if ((n - 1) % (K - 1) != 0) return -1;

        // prefix sum array
        vector<int> pre(n + 1, 0);
        for (int i = 0; i < n; i++)
            pre[i + 1] = pre[i] + stones[i];

        // dp[i][j] = minimum cost to merge stones[i..j]
        vector<vector<int>> dp(n, vector<int>(n, -1));

        return solve(0, n - 1, K, pre, dp);
    }
};



class Solution {
public:
    int getSum(vector<int>& pre, int i, int j) {
        return pre[j + 1] - pre[i];
    }

    int mergeStones(vector<int>& stones, int K) {
        int n = stones.size();
        if ((n - 1) % (K - 1) != 0) return -1;

        // prefix sum
        vector<int> pre(n + 1, 0);
        for (int i = 0; i < n; i++)
            pre[i + 1] = pre[i] + stones[i];

        // dp[i][j] = min cost to merge stones[i..j]
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));

        // base: single pile = 0 cost
        for (int i = 0; i < n; i++)
            dp[i][i] = 0;

        // length of interval
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                int ans = INT_MAX;

                // split at each (K - 1)
                for (int mid = i; mid < j; mid += (K - 1)) {
                    if (dp[i][mid] != INT_MAX && dp[mid + 1][j] != INT_MAX)
                        ans = min(ans, dp[i][mid] + dp[mid + 1][j]);
                }

                // can merge into 1 pile?
                if ((j - i) % (K - 1) == 0) {
                    ans += getSum(pre, i, j);
                }

                dp[i][j] = ans;
            }
        }

        return dp[0][n - 1];
    }
};


class Solution {
  public:
//   you can merge exactly k consecutive piles into a single pile, and the cost of this move is equal to the total number of stones in these k piles.
// Determine the minimum total cost required to merge all the piles into one single pile. If it is not possible to merge all piles into one according to the given rules, return -1.
    // Helper: range sum from prefix array
    int getSum(vector<int> &pre,int i,int j){
        return pre[j + 1] - pre[i];
    }
    // Recursive DP function with all major data passed by reference
    int solve(int i, int j, int m,vector<vector<vector<int>>>&dp,vector<int>&pre,int k){
        if(i==j)return (m == 1) ? 0 : INT_MAX;

        if(dp[i][j][m]!=-1)return dp[i][j][m];

        // if merging i..j into 1 pile:
        if (m == 1) {
            int cost = solve(i, j, k, dp, pre, k) + getSum(pre, i, j);
            return dp[i][j][m] = cost;
        }

        int ans = INT_MAX;
        // Try splitting
        for (int mid = i; mid < j; mid += (k - 1)) {
            ans = min(ans,solve(i,mid,1,dp,pre,k)+solve(mid+1,j,m-1,dp,pre,k));
        }

        return dp[i][j][m] = ans;
    }

    int mergeStones(vector<int>& stones, int k) {
        int n=stones.size();
        // Check if merging is possible
        if((n-1)%(k-1)!=0) return -1;

        // prefix sum
        vector<int>pre(n+1,0);
        for (int i=0;i<n;i++){
            pre[i+1]=pre[i]+stones[i];
        }

        // 3D DP (n x n x (K+1))
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(n,vector<int>(k+1,-1)));
        // Final: merge whole array to 1 pile
        return solve(0,n-1,1,dp,pre,k);
    }
};


class Solution {
public:
    int mergeStones(vector<int>& stones, int k) {
        int n = stones.size();

        // impossible case
        if ((n - 1) % (k - 1) != 0) return -1;

        // prefix sum
        vector<int> pre(n + 1, 0);
        for (int i = 0; i < n; i++)
            pre[i + 1] = pre[i] + stones[i];

        // dp[i][j] = min cost to merge stones[i..j] into 1 pile
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // length of subarray
        for (int len = k; len <= n; len++) {

            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                dp[i][j] = INT_MAX;

                // Try possible mid splits with (k-1) step
                for (int mid = i; mid < j; mid += (k - 1)) {
                    dp[i][j] = min(dp[i][j],
                                   dp[i][mid] + dp[mid + 1][j]);
                }

                // If we can merge into exactly 1 pile, add total sum
                if ((len - 1) % (k - 1) == 0) {
                    dp[i][j] += pre[j + 1] - pre[i];
                }
            }
        }

        return dp[0][n - 1];
    }
};
