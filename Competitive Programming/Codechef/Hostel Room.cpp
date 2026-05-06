#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n,x;
    cin>>n>>x;
    vector<int>arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];
    int sum=x;
    int maxPeople=sum;
    for(auto &num:arr){
        sum+=num;
        maxPeople=max(maxPeople,sum);
    }
    cout<<maxPeople<<"\n";
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
