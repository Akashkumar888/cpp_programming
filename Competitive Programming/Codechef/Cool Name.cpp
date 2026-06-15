#include <bits/stdc++.h>
using namespace std;

void solve(){

    string s;
    cin >> s;

    sort(s.begin(), s.end());

    long long power = 0;

    for(int i = 0; i < s.size(); i++){

        int val = (s[i] - 'a' + 1);

        power += 1LL * (i + 1) * val;
    }

    cout << power << "\n";
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
