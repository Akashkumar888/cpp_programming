
#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<int> freq(26, 0);
    for(char c : s) freq[c - 'a']++;

    for(int i = 0; i < 26; i++){
        if(freq[i] >= 2){
            cout << n - 2 << endl;
            return;
        }
    }

    cout << -1 << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--) solve();
}
