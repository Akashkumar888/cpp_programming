
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    // The operation essentially allows us to perform bubble sort
    // on the binary string. The lexicographically smallest 
    // string is just the sorted version of the original string.
    sort(s.begin(), s.end());
    
    cout << s << "\n";
}

int main() {
    // Fast I/O
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
