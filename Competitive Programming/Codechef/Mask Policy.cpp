#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n,a;
    cin>>n>>a;
    cout<<min(a,n-a)<<endl;
}
int main() {
	// your code goes here
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
