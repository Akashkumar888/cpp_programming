#include <bits/stdc++.h>
using namespace std;

void solve(){

    int n;
    cin>>n;

    vector<long long>arr(n);

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    sort(arr.begin(),arr.end());

    long long mx=arr[n-1];

    for(int i=n-2;i>=0;i--){

        if(arr[i]!=mx){

            cout<<arr[i]<<"\n";
            return;
        }
    }

    cout<<0<<"\n";
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
