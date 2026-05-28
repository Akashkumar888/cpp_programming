#include <bits/stdc++.h>
using namespace std;

void solve(){

    int n;
    cin>>n;

    vector<int>arr(n);

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    sort(arr.begin(),arr.end());

    long long maxWeight=0;

    for(int i=0;i<n;i++){

        long long legs=n-i;

        long long possibleWeight=1LL*arr[i]*legs;

        maxWeight=max(maxWeight,possibleWeight);
    }

    cout<<maxWeight<<"\n";
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--){
        solve();
    }
}
