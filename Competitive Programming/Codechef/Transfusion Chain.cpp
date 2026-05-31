#include <bits/stdc++.h>
using namespace std;

void solve(){

    int n;
    cin>>n;

    int A=0,B=0,AB=0,O=0;

    for(int i=0;i<n;i++){

        string blood;
        cin>>blood;

        if(blood=="A") A++;
        else if(blood=="B") B++;
        else if(blood=="AB") AB++;
        else O++;
    }

    int dpO=O;

    int dpA=A + dpO;

    int dpB=B + dpO;

    int dpAB=AB + max({dpO,dpA,dpB});

    cout<<max({dpO,dpA,dpB,dpAB})<<"\n";
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
