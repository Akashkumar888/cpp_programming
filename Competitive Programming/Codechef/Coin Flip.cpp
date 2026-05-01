#include <bits/stdc++.h>
using namespace std;

void solve(){
    int i,n,q;
    cin>>i>>n>>q;
    if(n % 2 == 0){
        cout << n/2 << "\n";
    }
    else{
        if(i == q) cout << n/2 << "\n";
        else cout << n/2 + 1 << "\n";
    }
}
int main() {
	// your code goes here
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int g;
        cin>>g;
        while(g--){
        solve();
        }
    }
}
