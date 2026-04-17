#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;

    int zeroCount = 0, oneCount = 0;

    for(char c : s){
        if(c == '0') zeroCount++;
        else oneCount++;
    }

    int ans = min(oneCount, 1 + zeroCount);
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
