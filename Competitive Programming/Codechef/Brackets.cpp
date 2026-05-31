#include <bits/stdc++.h>
using namespace std;

void solve(){

    string s;
    cin>>s;

    int balance=0;
    int maxBalance=0;

    for(char ch:s){

        if(ch=='('){
            balance++;
        }
        else{
            balance--;
        }

        maxBalance=max(maxBalance,
                       balance);
    }

    string result="";

    for(int i=0;i<maxBalance;i++){
        result+='(';
    }

    for(int i=0;i<maxBalance;i++){
        result+=')';
    }

    cout<<result<<"\n";
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
