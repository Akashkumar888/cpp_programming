#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, x, c;
    cin >> n >> x >> c;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    int total = 0;
    for(int i = 0; i < n; i++){
        int gain = x - arr[i];
        if(gain > c){
            total += (x - c); // upgraded value minus cost
        } else {
            total += arr[i]; // keep as it is
        }
    }
    cout << total <<endl;
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
