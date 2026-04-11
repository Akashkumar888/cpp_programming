#include <bits/stdc++.h>
using namespace std;

void solve(){
    int x,y,z;
    cin>>x>>y>>z;
    if(x>=y)cout<<"PIZZA"<<endl;
    else if(x>=z)cout<<"BURGER"<<endl;
    else cout<<"NOTHING"<<endl;
}
int main() {
	// your code goes here
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
