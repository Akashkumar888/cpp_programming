#include <bits/stdc++.h>
using namespace std;

void solve(){
    long long n,b,m;
    cin>>n>>b>>m;
    long long countTime = 0;
    while(n > 0){
        long long solveNow = (n + 2 - 1) / 2;   // ceil(n/2)

        countTime += solveNow * m;          // solving time
        n -= solveNow;                     // remaining problems

        if(n > 0){
            countTime += b;                // take break only if problems left
            m = 2 * m;                    // time doubles
        }
    }
    cout<<countTime<<endl;
}

int main() {
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
