#include <bits/stdc++.h>
using namespace std;

void solve(){

    int n, s;
    cin >> n >> s;

    vector<int> price(n);
    vector<int> type(n);

    for(int i = 0; i < n; i++){
        cin >> price[i];
    }

    for(int i = 0; i < n; i++){
        cin >> type[i];
    }

    int budget = 100 - s;

    bool possible = false;

    for(int i = 0; i < n; i++){

        if(type[i] != 0){
            continue;
        }

        for(int j = 0; j < n; j++){

            if(type[j] != 1){
                continue;
            }

            if(price[i] + price[j] <= budget){

                possible = true;
                break;
            }
        }

        if(possible){
            break;
        }
    }

    cout << (possible ? "yes" : "no") << "\n";
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}
