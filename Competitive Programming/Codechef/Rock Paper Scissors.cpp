#include <bits/stdc++.h>
using namespace std;

int win(char roku,char chef){

    if(chef=='R' && roku=='S') return 1;
    if(chef=='P' && roku=='R') return 1;
    if(chef=='S' && roku=='P') return 1;

    return 0;
}

void solve(){

    int n;
    cin>>n;

    string a;
    cin>>a;

    vector<char>moves={'R','P','S'};

    vector<vector<int>>dp(n,vector<int>(3,0));

    for(int m=0;m<3;m++){
        dp[0][m]=win(a[0],moves[m]);
    }

    for(int i=1;i<n;i++){

        for(int curr=0;curr<3;curr++){

            int best=0;

            for(int prev=0;prev<3;prev++){

                if(prev!=curr){
                    best=max(best,dp[i-1][prev]);
                }
            }

            dp[i][curr]=best+win(a[i],moves[curr]);
        }
    }

    cout<<max({dp[n-1][0],dp[n-1][1],dp[n-1][2]})<<"\n";
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
