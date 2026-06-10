
#include <bits/stdc++.h>
using namespace std;

void solve(){

    int A,B;
    cin>>A>>B;

    // palindrome impossible
    if(A%2==1 && B%2==1){

        cout<<"No\n";
        return;
    }

    // only one palindrome possible
    if(A==1 || B==1){

        cout<<"No\n";
        return;
    }

    cout<<"Yes\n";
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
