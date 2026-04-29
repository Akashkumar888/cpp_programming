#include <bits/stdc++.h>
using namespace std;

void solve(){
    string s;
    cin>>s;
    long long sum=0;
    for(char &ch:s){
        if(ch>='0' && ch<='9'){
            sum+=(ch-'0');
        }
    }
    cout<<sum<<endl;
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
