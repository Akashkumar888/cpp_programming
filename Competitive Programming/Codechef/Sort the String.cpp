#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;

    int cnt = 0;
    // We simply count every occurrence of "10"
    for(int i = 0; i < n - 1; i++){
        if(s[i] == '1' && s[i+1] == '0'){
            cnt++;
        }
    }

    // The answer is simply the count of "10" substrings
    cout << cnt << endl;
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
