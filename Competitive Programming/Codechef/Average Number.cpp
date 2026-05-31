#include <bits/stdc++.h>
using namespace std;

void solve(){

    int n,k,v;
    cin>>n>>k>>v;

    vector<int>arr(n);

    int sum=0;

    for(int i=0;i<n;i++){
        cin>>arr[i];
        sum+=arr[i];
    }

    int totalSum=(n+k)*v;

    int deletedSum=totalSum-sum;

    if(deletedSum<=0 || deletedSum%k!=0){

        cout<<-1<<"\n";
        return;
    }

    cout<<deletedSum/k<<"\n";
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
