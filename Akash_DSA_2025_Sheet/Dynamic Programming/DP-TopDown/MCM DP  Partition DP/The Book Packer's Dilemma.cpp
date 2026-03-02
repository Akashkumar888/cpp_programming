
// =====================
// 🔹 Headers
// =====================
#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;


// =====================
// 🔹 Core Logic Function
// =====================
int user_logic(int n, int maxBooks, int k, const vector<int>& books) {

    vector<int> vals = {0};
    for(int x : books) vals.push_back(x);

    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());

    int V = vals.size();
    int K = k;
    int M = maxBooks;

    auto getIndex = [&](int v) {
        return lower_bound(vals.begin(), vals.end(), v) - vals.begin();
    };

    vector<vector<vector<int>>> dp(
        K + 1,
        vector<vector<int>>(M + 1, vector<int>(V, INF))
    );

    dp[0][0][0] = 0;

    for(int i = 0; i < n; i++) {

        int bv = books[i];
        int bi = getIndex(bv);

        vector<vector<vector<int>>> ndp(
            K + 1,
            vector<vector<int>>(M + 1, vector<int>(V, INF))
        );

        for(int r = 0; r <= K; r++) {
            for(int c = 0; c <= M; c++) {
                for(int m = 0; m < V; m++) {

                    if(dp[r][c][m] == INF) continue;

                    int cost = dp[r][c][m];
                    int curMax = vals[m];

                    if(r < K)
                        ndp[r+1][c][m] =
                            min(ndp[r+1][c][m], cost);

                    int newMax = (c == 0) ? bv : max(curMax, bv);
                    int nm = getIndex(newMax);
                    int nc = c + 1;

                    if(nc == M)
                        ndp[r][0][0] =
                            min(ndp[r][0][0], cost + newMax);
                    else
                        ndp[r][nc][nm] =
                            min(ndp[r][nc][nm], cost);

                    if(c > 0) {
                        int costAfterClose = cost + curMax;

                        if(1 == M)
                            ndp[r][0][0] =
                                min(ndp[r][0][0],
                                    costAfterClose + bv);
                        else
                            ndp[r][1][bi] =
                                min(ndp[r][1][bi],
                                    costAfterClose);
                    }
                }
            }
        }

        dp = ndp;
    }

    int ans = INF;

    for(int r = 0; r <= K; r++)
        for(int c = 0; c <= M; c++)
            for(int m = 0; m < V; m++)
                if(dp[r][c][m] != INF)
                    ans = min(ans,
                              dp[r][c][m] +
                              (c > 0 ? vals[m] : 0));

    return ans;
}


// =====================
// 🔹 Main Function
// =====================
int main() {

    int n, maxBooks, k;
    cin >> n >> maxBooks >> k;

    vector<int> books(n);
    for(int i = 0; i < n; i++)
        cin >> books[i];

    cout << user_logic(n, maxBooks, k, books) << endl;

    return 0;
}