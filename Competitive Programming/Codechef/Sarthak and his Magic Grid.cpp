#include <bits/stdc++.h>
using namespace std;

void solve(){

    int n;
    cin >> n;

    for(int i = 0; i < n; i++){

        for(int j = 0; j < n; j++){

            cout << 1;

            if(j + 1 < n){
                cout << " ";
            }
        }

        cout << "\n";
    }
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
