#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;

    vector<int> maxScore(12, 0); // index 1 to 11

    for(int i = 0; i < n; i++){
        int p, s;
        cin >> p >> s;

        if(p <= 8){ // only scorable problems
            maxScore[p] = max(maxScore[p], s);
        }
    }

    int total = 0;
    for(int i = 1; i <= 8; i++){
        total += maxScore[i];
    }

    cout << total << endl;
}

int main() {
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
