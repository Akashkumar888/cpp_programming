#include <bits/stdc++.h>
using namespace std;

void solve(){

    int n, k, d;
    cin >> n >> k >> d;

    vector<int> t(n);

    for(int i = 0; i < n; i++){
        cin >> t[i];
    }

    int free = n - k;

    if(free == 0){
        cout << 0 << "\n";
        return;
    }

    sort(t.begin(), t.end());

    long long ans = 0;

    for(int i = 0; i < free; i++){

        ans += (d - 1) / t[i] + 1;
    }

    cout << ans << "\n";
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int tc;
    cin >> tc;

    while(tc--){
        solve();
    }

    return 0;
}
