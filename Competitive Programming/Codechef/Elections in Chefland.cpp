#include <bits/stdc++.h>
using namespace std;

void solve(){
    int Xa,Xb,Xc;
    cin>>Xa>>Xb>>Xc;
    if(Xa>50)cout<<"A"<<endl;
    else if(Xb>50)cout<<"B"<<endl;
    else if(Xc>50)cout<<"C"<<endl;
    else cout<<"NOTA"<<endl;
}
int main() {
	// your code goes here
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
