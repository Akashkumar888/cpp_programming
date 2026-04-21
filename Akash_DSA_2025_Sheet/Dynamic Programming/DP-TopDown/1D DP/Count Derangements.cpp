// Key Observation (Recurrence)
// The number of derangements follows this recurrence:
// 👉 D(n) = (n - 1) × (D(n - 1) + D(n - 2))

// Base cases:
// D(1) = 0
// D(2) = 1

// 🔹 3. Why this formula works (intuition)
// Pick element 1:
// It cannot go to position 1
// Suppose it goes to position k
// Now two cases:
// Element at position k goes to position 1 → remaining (n-2) → D(n-2)
// It does NOT go to position 1 → remaining (n-1) → D(n-1)
// Multiply by (n-1) choices → total:
// 👉 (n-1) * (D(n-1) + D(n-2))

class Solution {
  public:
    int solve(int n, vector<int>& dp) {
        // Base cases
        if(n == 1) return 0;
        if(n == 2) return 1;

        // If already computed
        if(dp[n] != -1) return dp[n];

        // Recurrence
        return dp[n] = (n - 1) * (solve(n - 1, dp) + solve(n - 2, dp));
    }

    int derangeCount(int n) {
        vector<int> dp(n + 1, -1);
        return solve(n, dp);
    }
};

class Solution {
  public:
    int derangeCount(int n) {
        if(n == 1) return 0;
        if(n == 2) return 1;

        vector<int> dp(n + 1);

        dp[1] = 0;
        dp[2] = 1;

        for(int i = 3; i <= n; i++) {
            dp[i] = (i - 1) * (dp[i - 1] + dp[i - 2]);
        }

        return dp[n];
    }
};

class Solution {
  public:
    int derangeCount(int n) {
        if(n == 1) return 0;
        if(n == 2) return 1;

        int prev2 = 0; // D(1)
        int prev1 = 1; // D(2)

        for(int i = 3; i <= n; i++) {
            int curr = (i - 1) * (prev1 + prev2);
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};
