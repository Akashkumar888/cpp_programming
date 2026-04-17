#include <bits/stdc++.h>
using namespace std;
void solve(){
    long long n,m;
    cin>>n>>m;
    vector<long long>arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];
    long long maxDist=0;
    for(int i=0;i<n;i++){
        long long dist1 = abs(arr[i] - 1);
        long long dist2 = abs(arr[i] - m);
        maxDist += max(dist1, dist2);
    }
    cout<<maxDist<<endl;
}

int main() {
	// your code goes here
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
