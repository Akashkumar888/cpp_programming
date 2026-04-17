#include <bits/stdc++.h>
using namespace std;

void solve(){
    int a, b, x;
    cin >> a >> b >> x;

    if(a == b){
        cout << "YES"<<endl;
        return;
    }

    int diff = b - a;

    if(diff % (2 * x) == 0){
        cout << "YES"<<endl;
    } 
    else {
        cout << "NO"<<endl;
    }
}

int main() {
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
