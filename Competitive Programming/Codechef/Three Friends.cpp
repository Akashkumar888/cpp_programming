#include <bits/stdc++.h>
using namespace std;

void solve(){
    int x,y,z;
    cin>>x>>y>>z;
    if(x+y==z){
        cout<<"YES"<<endl;
    }
    else if(y+z==x){
        cout<<"YES"<<endl;
    }
    else if(z+x==y) {
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
}
int main() {
	// your code goes here
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
