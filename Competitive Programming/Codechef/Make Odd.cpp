#include <bits/stdc++.h>
using namespace std;

void solve(){

    int n;
    cin>>n;

    string a,b;
    cin>>a>>b;

    int fixedOne=0;
    int choice=0;

    for(int i=0;i<n;i++){

        if(a[i]=='1' && b[i]=='1'){
            fixedOne++;
        }
        else if(a[i]!=b[i]){
            choice++;
        }
    }

    if(fixedOne%2==1){
        cout<<"YES\n";
    }
    else if(choice>0){
        cout<<"YES\n";
    }
    else{
        cout<<"NO\n";
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
