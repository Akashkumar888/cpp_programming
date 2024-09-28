#include <bits/stdc++.h>
using namespace std;

using ll = long long;
vector<ll> dp;
vector<ll> sums;

ll calc(vector<vector<ll>>& compat, int mask) {
    ll ans = 0;
    int n = compat.size();
    for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if ( (mask & (1 << i)) &&( mask & (1 << j)) ) {
                    ans += compat[i][j];
                }
        }
    }
    return ans;
}

void precompute(vector<vector<ll>>& compat, int n) {
    for (int mask = 1; mask < (1 << n); mask++) {
        sums[mask] = calc(compat, mask);
    }
}

ll f(vector<vector<ll>>& compat, int mask) {
    if (mask == 0) return 0;
    if (dp[mask] != LLONG_MAX) return dp[mask];

    ll ans = 0;
    for (int g = mask; g != 0; g = (g - 1) & mask) {
        ans = max(ans, sums[g] + f(compat, mask ^ g));
    }
    return dp[mask] = ans;
}

int main() {
    int n;
    cin >> n;

    vector<vector<ll>> compat(n, vector<ll>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> compat[i][j];
        }
    }

    dp.resize(1 << n, LLONG_MAX);
    sums.resize(1 << n, 0);

    precompute(compat, n);
    cout << f(compat, (1 << n) - 1) << endl;

    return 0;
}
