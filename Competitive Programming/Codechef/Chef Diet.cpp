#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n,k;
    cin>>n>>k;
    vector<int>arr(n,0);
    for(int i=0;i<n;i++)cin>>arr[i];
    int sum=0;
    for(int i=0;i<n;i++){
        if(arr[i]+sum<k){
            cout<<"NO"<<" "<<i+1<<endl;
            return;
        }
        sum=sum+arr[i]-k;
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
