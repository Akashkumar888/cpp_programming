#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;

    vector<int> lrr(n), grr(n);
    for(int i = 0; i < n; i++) cin >> lrr[i];
    for(int i = 0; i < n; i++) cin >> grr[i];

    bool canFront = true, canBack = true;

    for(int i = 0; i < n; i++){
        if(lrr[i] > grr[i]) canFront = false;
        if(lrr[i] > grr[n - 1 - i]) canBack = false;
    }

    if(canFront && canBack) cout << "both"<<endl;
    else if(canFront) cout << "front"<<endl;
    else if(canBack) cout << "back"<<endl;
    else cout << "none"<<endl;
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
