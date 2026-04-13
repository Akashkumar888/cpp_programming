#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, m;
    cin >> n >> m;

    int rows = (n + 1) / 2;   // usable rows
    int seats = (m + 1) / 2;  // usable seats per row

    cout << rows * seats << endl;
}

int main() {
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
