#include <bits/stdc++.h>
using namespace std;

void solve(){

    long long N,K,S;
    cin>>N>>K>>S;

    long long sumOdd=N*N;

    long long repeated=(S-sumOdd)/(K-1);

    cout<<repeated<<"\n";
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--){

        solve();
    }

    return 0;
}
