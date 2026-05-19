
#include <bits/stdc++.h>
using namespace std;

void solve(){

    int n;
    cin>>n;

    int zero=0,one=0;

    for(int i=0;i<n;i++){
        int x;
        cin>>x;

        if(x==0) zero++;
        else one++;
    }

    cout<<min(zero,one)<<"\n";
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
