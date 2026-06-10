#include <bits/stdc++.h>
using namespace std;

long long nCr(int n, int r){

    if(r > n) return 0;

    long long ans = 1;

    for(int i = 1; i <= r; i++){
        ans = ans * (n - i + 1) / i;
    }

    return ans;
}

void solve(){

    int x, n;
    cin >> x >> n;

    long long ways = 0;

    while(n--){

        string s;
        cin >> s;

        for(int comp = 0; comp < 9; comp++){

            int freeSeats = 0;

            int a = 4 * comp;
            int b = 53 - 2 * comp;
            int c = 52 - 2 * comp;

            // first 4 seats
            for(int j = a; j < a + 4; j++){

                if(s[j] == '0'){
                    freeSeats++;
                }
            }

            // last 2 seats
            if(s[b] == '0'){
                freeSeats++;
            }

            if(s[c] == '0'){
                freeSeats++;
            }

            ways += nCr(freeSeats, x);
        }
    }

    cout << ways << "\n";
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
