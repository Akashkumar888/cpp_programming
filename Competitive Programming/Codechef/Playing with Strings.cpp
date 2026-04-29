#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    string r;
    cin>>r;
    int onesS=0;
    int onesR=0;
    for(int i=0;i<n;i++){
        if(s[i]=='1')onesS++;
        if(r[i]=='1')onesR++;
    }
    if(onesR!=onesS)cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
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
