#include <bits/stdc++.h>
using namespace std;

void solve(){

    long long A, B, N;
    cin >> A >> B >> N;

    if(A % B == 0){
        cout << -1 << "\n";
        return;
    }

    long long x = ((N + A - 1) / A) * A;

    while(x % B == 0){
        x += A;
    }

    cout << x << "\n";
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
