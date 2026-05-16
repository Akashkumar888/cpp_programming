#include <bits/stdc++.h>
using namespace std;

void solve(){

    int d,x,y;
    cin>>d>>x>>y;

    if(y>=x){
        cout<<0<<"\n";
        return;
    }

    for(int session=1;session<=100;session++){

        int money=y-session;

        if(money<0) break;

        int discount=session*d;

        if(discount>100){
            discount=100;
        }

        if(money*100 >= x*(100-discount)){

            cout<<session<<"\n";
            return;
        }
    }

    cout<<-1<<"\n";
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
