#include <bits/stdc++.h>
using namespace std;

void solve(){

    int n, k;
    cin >> n >> k;

    vector<int> arr(n);

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int answer = -1;

    for(int &num : arr){

        // can capture chef
        if(k % num == 0){

            // larger num -> fewer moves
            answer = max(answer, num);
        }
    }

    cout << answer << "\n";
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
