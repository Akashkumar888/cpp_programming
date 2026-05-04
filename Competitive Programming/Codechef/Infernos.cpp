#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, x;
    cin >> n >> x;

    vector<int> hrr(n);
    for(int i = 0; i < n; i++) cin >> hrr[i];

    // Single-target mode
    int singleTime = 0;
    for(int i = 0; i < n; i++) {
        singleTime += (hrr[i] + x - 1) / x; // ceil
    }

    // Multi-target mode
    int multiTime = *max_element(hrr.begin(), hrr.end());

    cout << min(singleTime, multiTime) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
