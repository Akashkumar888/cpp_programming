#include <bits/stdc++.h>
using namespace std;

void solve(){

    int n,y;
    cin>>n>>y;

    vector<int>arr(n);

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int OR=0;

    for(int &num:arr){
        OR|=num;
    }

    // impossible if OR has extra bits
    if((OR & (~y)) != 0){

        cout<<-1<<"\n";
        return;
    }

    // add missing bits only
    int x = y ^ OR;

    cout<<x<<"\n";
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--){
        solve();
    }
}
