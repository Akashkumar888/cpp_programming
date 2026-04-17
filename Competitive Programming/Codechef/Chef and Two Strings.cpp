#include <bits/stdc++.h>
using namespace std;

void solve(){
    string s1, s2;
    cin >> s1 >> s2;

    int n = s1.size();
    int minDiff = 0, maxDiff = 0;

    for(int i = 0; i < n; i++){
        if(s1[i] == s2[i]){
            if(s1[i] == '?'){
                // both '?'
                maxDiff++; // can make different
            }
            // else same letters → nothing
        }
        else{
            if(s1[i] == '?' || s2[i] == '?'){
                // can match for min, differ for max
                maxDiff++;
            }
            else{
                // both different letters
                minDiff++;
                maxDiff++;
            }
        }
    }

    cout << minDiff << " " << maxDiff << endl;
}

int main() {
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
