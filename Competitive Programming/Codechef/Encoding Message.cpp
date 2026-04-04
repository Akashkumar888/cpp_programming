#include <bits/stdc++.h>
using namespace std;


void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    // Step 1: swap adjacent
    for(int i = 0; i + 1 < n; i += 2){
        swap(s[i], s[i+1]);
    }

    // Step 2: convert characters
    for(int i = 0; i < n; i++){
        s[i] = 'a' + ('z' - s[i]);
    }

    cout << s <<endl;
}
int main() {
	// your code goes here
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
