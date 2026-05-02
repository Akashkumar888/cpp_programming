#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    if(s[0]=='0'){
        s[0]='1';
        k--;
    }
    while(k--){
        s.push_back('0');
    }
    cout<<s<<"\n";
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
