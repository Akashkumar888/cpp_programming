#include <bits/stdc++.h>
using namespace std;

void solve(){

    string s;
    cin>>s;

    int n=s.size();

    string leftShift="";
    string rightShift="";

    for(int i=1;i<n;i++){
        leftShift+=s[i];
    }

    leftShift+=s[0];

    rightShift+=s[n-1];

    for(int i=0;i<n-1;i++){
        rightShift+=s[i];
    }

    if(leftShift==rightShift){
        cout<<"YES\n";
    }
    else{
        cout<<"NO\n";
    }
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--){
        solve();
    }
}
