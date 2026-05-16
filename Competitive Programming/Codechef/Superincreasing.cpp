#include <bits/stdc++.h>
using namespace std;

void solve(){

    int n,k;
    long long x;

    cin>>n>>k>>x;

    long long value=1;

    for(int i=1;i<k;i++){

        value*=2;

        if(value>1e9){
            break;
        }
    }

    if(x>=value){
        cout<<"Yes\n";
    }
    else{
        cout<<"No\n";
    }
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
