#include <bits/stdc++.h>
using namespace std;

void solve() {

    int n;
    cin >> n;

    vector<int> x(n);

    for(int i = 0; i < n; i++) {
        cin >> x[i];
    }

    int mini = n;
    int maxi = 1;

    int cnt = 1;

    for(int i = 1; i < n; i++) {

        if(x[i] - x[i - 1] <= 2) {
            cnt++;
        }
        else {
            mini = min(mini, cnt);
            maxi = max(maxi, cnt);
            cnt = 1;
        }
    }

    mini = min(mini, cnt);
    maxi = max(maxi, cnt);

    cout << mini << " " << maxi << "\n";
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}
