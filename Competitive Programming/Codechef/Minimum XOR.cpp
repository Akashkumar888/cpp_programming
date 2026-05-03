#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];
    int minXor=0;
    for(int &num:arr)minXor^=num;
    int totalXor=minXor;
    for(int &num:arr){
        minXor=min(minXor,totalXor^num);
    }
    cout<<minXor<<"\n";
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
