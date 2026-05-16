#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n,a;
    cin>>n>>a;
    // square 4a or a*a use 
    int k = sqrt(n);      // largest k such that k*k ≤ n
    cout<<k*a<<"\n";// a 
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
