#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n,k;
    cin>>n>>k;
    vector<int>arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];
    string result="";
    for(int i=0;i<n;i++){
        if(arr[i]%k==0)result+='1';
        else result+='0';
    }
    cout<<result<<endl;
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
