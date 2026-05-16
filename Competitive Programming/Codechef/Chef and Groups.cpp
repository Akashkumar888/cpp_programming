#include <bits/stdc++.h>
using namespace std;

void solve(){
    string s;
    cin>>s;
    int ones=0;
    int maxCount=0;
    for(char &ch:s){
        if(ch=='1')ones++;
        else{
            maxCount+=(ones?1:0);
            ones=0;
        }
    }
    maxCount+=(ones?1:0);
    cout<<maxCount<<"\n";
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
