#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    
    string s;
    cin >> s;

    // Condition 1: length must be even
    if(n % 2 != 0){
        cout << "NO"<<endl;
        return;
    }

    // Frequency count
    vector<int> freq(26, 0);
    for(char c : s){
        freq[c - 'a']++;
    }

    // Condition 2: all frequencies must be even
    for(int i = 0; i < 26; i++){
        if(freq[i] % 2 != 0){
            cout << "NO"<<endl;
            return;
        }
    }

    cout << "YES"<<endl;
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
