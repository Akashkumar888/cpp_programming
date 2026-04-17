
#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];
    map<int,int>mp;
    for(int num:arr)mp[num]++;
    for(auto &it:mp){
        if((it.second)%(it.first)!=0){
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
}
int main() {
	// your code goes here
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
