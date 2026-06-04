#include <bits/stdc++.h>
using namespace std;

void solve(){

    int n;
    cin>>n;

    string s;
    cin>>s;

    int firstZero=-1;

    for(int i=0;i<n;i++){

        if(s[i]=='0'){

            firstZero=i;
            break;
        }
    }

    if(firstZero==-1){

        cout<<n<<"\n";
    }
    else{

        cout<<firstZero<<"\n";
    }
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
