#include <bits/stdc++.h>
using namespace std;

void solve(){

    string a, b;
    cin >> a >> b;

    int n = a.size();

    int a0 = 0, a1 = 0;
    int b0 = 0, b1 = 0;

    for(char ch : a){
        if(ch == '0') a0++;
        else a1++;
    }

    for(char ch : b){
        if(ch == '0') b0++;
        else b1++;
    }

    int ones = min(a0, b1) + min(a1, b0);

    string ans;

    ans.append(ones, '1');
    ans.append(n - ones, '0');

    cout << ans << "\n";
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
