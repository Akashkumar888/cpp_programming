#include <bits/stdc++.h>
using namespace std;

void solve(){

    int n;
    cin>>n;

    unordered_map<char,int>mp;

    for(int i=0;i<n;i++){

        string s;
        cin>>s;

        for(char ch:s){
            mp[ch]++;
        }
    }

    int meals=INT_MAX;

    meals=min(meals,mp['c']/2);
    meals=min(meals,mp['o']);
    meals=min(meals,mp['d']);
    meals=min(meals,mp['e']/2);
    meals=min(meals,mp['h']);
    meals=min(meals,mp['f']);

    cout<<meals<<"\n";
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
