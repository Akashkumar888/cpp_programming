#include <bits/stdc++.h>
using namespace std;

void solve(){

    int A,B,P,Q;
    cin >> A >> B >> P >> Q;

    // already at destination
    if(A==P && B==Q){

        cout << 0 << "\n";
        return;
    }

    int startColor=(A+B)%2;
    int endColor=(P+Q)%2;

    // different color -> direct move
    if(startColor!=endColor){

        cout << 1 << "\n";
    }
    else{

        // same color -> need intermediate cell
        cout << 2 << "\n";
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
