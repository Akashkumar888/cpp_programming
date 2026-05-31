#include <bits/stdc++.h>
using namespace std;

void solve(){

    int n;
    cin>>n;

    vector<int>freq(10,0);

    for(int i=0;i<n;i++){

        string s;
        cin>>s;

        for(int j=0;j<10;j++){

            if(s[j]=='1'){
                freq[j]++;
            }
        }
    }

    int count=0;

    for(int i=0;i<10;i++){

        if(freq[i]%2){
            count++;
        }
    }

    cout<<count<<"\n";
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
