#include <bits/stdc++.h>
using namespace std;

void solve(){
    string s;
    cin >> s;

    int n = s.size();

    // Step 1: flip the string
    for (char &c : s) {
        if (c == '>') c = '<';
        else if (c == '<') c = '>';
    }

    // Step 2: count "><"
    int count = 0;
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == '>' && s[i+1] == '<') {
            count++;
        }
    }

    cout << count << endl;
}

int main() {
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
