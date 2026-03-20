
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int minWetCells(int N, int M, vector<vector<int>>& grid) {

    const int INF = 1e9;

    vector<vector<vector<int>>> dp(N, vector<vector<int>>(M, vector<int>(2, INF)));

    // Starting cell
    if(grid[0][0] == 1)
        dp[0][0][0] = 1;
    else
        dp[0][0][0] = 0;

    if(grid[0][0] == 2)
        dp[0][0][1] = 0;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            for(int u = 0; u <= 1; u++) {

                if(dp[i][j][u] == INF) continue;

                // move right
                if(j + 1 < M) {
                    int nu = u;
                    int cost = dp[i][j][u];

                    if(grid[i][j+1] == 1 && nu == 0)
                        cost++;

                    if(grid[i][j+1] == 2)
                        nu = 1;

                    dp[i][j+1][nu] = min(dp[i][j+1][nu], cost);
                }

                // move down
                if(i + 1 < N) {
                    int nu = u;
                    int cost = dp[i][j][u];

                    if(grid[i+1][j] == 1 && nu == 0)
                        cost++;

                    if(grid[i+1][j] == 2)
                        nu = 1;

                    dp[i+1][j][nu] = min(dp[i+1][j][nu], cost);
                }
            }
        }
    }

    int ans = min(dp[N-1][M-1][0], dp[N-1][M-1][1]);

    if(ans == INF) return -1;

    return ans;
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> grid(N, vector<int>(M));

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> grid[i][j];
        }
    }

    cout << minWetCells(N, M, grid);

    return 0;
}