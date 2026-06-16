#include <bits/stdc++.h>
using namespace std;

void solve(){

    long long n, s;
    cin >> n >> s;

    long long cnt6 = max(0LL, s - 5 * n);

    cout << 6 * n - cnt6 << "\n";
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
