#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end(),greater<int>());

    /*
        Make pattern:

        A[0] <= A[1] >= A[2] <= A[3]

        swap adjacent pairs
        at odd positions
    */

    for(int i = 1; i < n; i += 2){
        swap(arr[i], arr[i - 1]);
    }
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }

    cout << "\n";
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
