#include <bits/stdc++.h>
using namespace std;

void solve(){
    long long n, x;
    cin >> n >> x;

    if(n % 2 == 0){
        cout << "YES\n";
    }
    else{
        if(x % 2 == 1) cout << "YES"<<endl;
        else cout << "NO"<<endl;
    }
}
int main() {
	// your code goes here
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
