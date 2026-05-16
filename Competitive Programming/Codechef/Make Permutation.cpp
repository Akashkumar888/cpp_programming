#include <bits/stdc++.h>
using namespace std;

void solve(){

    int n;
    cin >> n;

    vector<int> arr(n);

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    int current = 1;

    for(int i = 0; i < n; i++){

        // move current until valid
        current = max(current, arr[i]);

        // no number available
        if(current > n){

            cout << "NO\n";
            return;
        }

        // assign this number
        current++;
    }

    cout << "YES\n";
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
