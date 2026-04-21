#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    map<int,int>mp;
    for(int i=0;i<n;i++)mp[arr[i]]++;
    int maxFreq=0;
    for(auto &it:mp)maxFreq=max(maxFreq,it.second);
    cout<<n-maxFreq<<endl;
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
