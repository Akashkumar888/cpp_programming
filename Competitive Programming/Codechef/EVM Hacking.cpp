#include <bits/stdc++.h>
using namespace std;

void solve(){

    int A, B, C, P, Q, R;
    cin >> A >> B >> C >> P >> Q >> R;

    int total = P + Q + R;

    if(A + B + C > total / 2.0){
        cout << "YES\n";
        return;
    }

    if(P + B + C > total / 2.0){
        cout << "YES\n";
        return;
    }

    if(A + Q + C > total / 2.0){
        cout << "YES\n";
        return;
    }

    if(A + B + R > total / 2.0){
        cout << "YES\n";
        return;
    }

    cout << "NO\n";
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
