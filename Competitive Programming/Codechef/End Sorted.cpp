#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];

    int pos1 = -1, posN = -1;

    for(int i = 0; i < n; i++){
        if(arr[i] == 1) pos1 = i;
        if(arr[i] == n) posN = i;
    }

    int ans = (pos1 - 0) + (n - 1 - posN);

    if(pos1 > posN) ans--;  // 🔥 important fix

    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
