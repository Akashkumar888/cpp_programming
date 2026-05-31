#include <bits/stdc++.h>
using namespace std;

void solve(){

    int n,x;
    cin>>n>>x;

    int small=0;
    int big=0;
    int equal=0;

    for(int i=0;i<n;i++){

        int num;
        cin>>num;

        if(num<x){
            small++;
        }
        else if(num>x){
            big++;
        }
        else{
            equal++;
        }
    }

    if(equal>0){
        cout<<"Yes\n";
    }
    else if(small==0 || big==0){
        cout<<"Yes\n";
    }
    else{
        cout<<"No\n";
    }
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
