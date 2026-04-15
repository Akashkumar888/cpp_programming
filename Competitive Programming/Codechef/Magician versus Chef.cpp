#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, x, s;
    cin >> n >> x >> s;

    for(int i = 0; i < s; i++){
        int a, b;
        cin >> a >> b;

        if(x == a){
            x = b;
        }
        else if(x == b){
            x = a;
        }
    }

    cout << x << endl;
}

int main() {
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
