
#include <bits/stdc++.h>
using namespace std;

void solve(){
    int d1,t1,m1; // Dragon
    int d2,t2,m2; // Sloth
    
    cin>>d1>>t1>>m1;
    cin>>d2>>t2>>m2;
    
    int sum1 = d1 + t1 + m1;
    int sum2 = d2 + t2 + m2;
    
    if(sum1 > sum2) cout<<"Dragon"<<endl;
    else if(sum2 > sum1) cout<<"Sloth"<<endl;
    else{
        if(d1 > d2) cout<<"Dragon"<<endl;
        else if(d2 > d1) cout<<"Sloth"<<endl;
        else{
            if(t1 > t2) cout<<"Dragon"<<endl;
            else if(t2 > t1) cout<<"Sloth"<<endl;
            else cout<<"Tie"<<endl;
        }
    }
}

int main() {
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
