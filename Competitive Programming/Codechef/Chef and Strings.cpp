#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;

    vector<int> s(n);
    for(int i = 0; i < n; i++){
        cin >> s[i];
    }

    long long totalSkip = 0;

    for(int i = 1; i < n; i++){
        totalSkip += abs(s[i] - s[i-1]) - 1;
    }

    cout << totalSkip << endl;
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
