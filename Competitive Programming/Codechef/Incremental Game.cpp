#include <bits/stdc++.h>
using namespace std;

int dp[21][21][21];

bool solveGame(int x, int y, int last){

    if(dp[x][y][last] != -1){
        return dp[x][y][last];
    }

    for(int take = last + 1; take <= x; take++){

        if(!solveGame(x - take, y, take)){
            return dp[x][y][last] = 1;
        }
    }

    for(int take = last + 1; take <= y; take++){

        if(!solveGame(x, y - take, take)){
            return dp[x][y][last] = 1;
        }
    }

    return dp[x][y][last] = 0;
}

void solve(){

    int x, y, k;
    cin >> x >> y >> k;

    memset(dp, -1, sizeof(dp));

    bool aliceWins = false;

    // Alice's first move from pile X
    for(int take = 1; take <= min(k, x); take++){

        if(!solveGame(x - take, y, take)){
            aliceWins = true;
            break;
        }
    }

    // Alice's first move from pile Y
    if(!aliceWins){

        for(int take = 1; take <= min(k, y); take++){

            if(!solveGame(x, y - take, take)){
                aliceWins = true;
                break;
            }
        }
    }

    cout << (aliceWins ? "Alice" : "Bob") << "\n";
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}
