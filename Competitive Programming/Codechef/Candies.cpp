#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int>arr(2*n);
    for(int i=0;i<2*n;i++)cin>>arr[i];
    unordered_map<int,int>mp;
    for(int &num:arr)mp[num]++;
    for(auto &it:mp){
        if(it.second>2){
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
