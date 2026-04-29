#include <bits/stdc++.h>
using namespace std;

void solve(){
    long long l,k;
    cin>>l>>k;

    if(l % k == 0) cout<<0<<endl;
    else cout<<1<<endl;
//     Because:
// You can group all base together
// And all (base+1) together
// 👉 So only one boundary
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
