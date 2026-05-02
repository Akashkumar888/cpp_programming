#include <bits/stdc++.h>
using namespace std;

void solve(){
    int x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    if((x1 + y1) % 2 == (x2 + y2) % 2)cout << "YES\n";
    else cout<<"NO\n";
}
int main() {
	// your code goes here
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
