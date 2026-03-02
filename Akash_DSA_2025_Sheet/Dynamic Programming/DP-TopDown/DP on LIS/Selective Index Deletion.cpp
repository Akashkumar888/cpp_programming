
#include <bits/stdc++.h>
using namespace std;

int minDeletions(int n, const vector<int>& arr) {
    vector<int> dp(n, 1);
    int maxLen = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] % (dp[j] + 1) == 0) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        maxLen = max(maxLen, dp[i]);
    }

    return n - maxLen;
}

