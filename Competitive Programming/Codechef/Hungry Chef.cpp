#include <bits/stdc++.h>
using namespace std;

void solve(){

    long long x, y, n, r;
    cin >> x >> y >> n >> r;

    // impossible case
    if(n * x > r){
        cout << -1 << "\n";
        return;
    }

    // maximum premium burgers possible
    long long premium = min(n, (r - n * x) / (y - x));

    // remaining burgers are normal
    long long normal = n - premium;

    cout << normal << " " << premium << "\n";
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
