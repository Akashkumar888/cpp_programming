// Answer = N - (maximum frequency of any number)
#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];

    unordered_map<int,int> freq;

    int maxFreq = 0;

    for(int i = 0; i < n; i++){
        freq[arr[i]]++;
        maxFreq = max(maxFreq, freq[arr[i]]);
    }

    cout << n - maxFreq << endl;
}

int main() {
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
