#include <bits/stdc++.h>
using namespace std;

void solve(){
    vector<int> price(26);
    for(int i = 0; i < 26; i++){
        cin >> price[i];
    }

    string s;
    cin >> s;

    vector<int> mp(26, 0);

    // mark present characters
    for(char &ch : s){
        mp[ch - 'a']++;
    }

    long long sum = 0;

    // check missing characters
    for(int i = 0; i < 26; i++){
        if(mp[i] == 0){
            sum += price[i];   // use given price
        }
    }

    cout << sum <<endl;
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
