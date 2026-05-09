#include <bits/stdc++.h>
using namespace std;

// Berth Number   	Compartment
// 1 -  8               1
// 9 - 16               2
// 17 - 24               3
// ... and so on


//  1LB,  2MB,  3UB,  4LB,  5MB,  6UB,  7SL,  8SU  
//  9LB, 10MB, ...
 
 
// 3UB   |  6UB  
// 2MB   |  5MB  
// 1LB   |  4LB  

// 7SL   |  8SU  

void solve(){
    int n;
    cin>>n;
    int val=(n%8);
    if(val==7)cout<<n+1<<"SU\n";
    else if(val==0)cout<<n-1<<"SL\n";
    else if(val==1)cout<<n+3<<"LB\n";
    else if(val==4)cout<<n-3<<"LB\n";
    else if(val==2)cout<<n+3<<"MB\n";
    else if(val==5)cout<<n-3<<"MB\n";
    else if(val==3)cout<<n+3<<"UB\n";
    else if(val==6)cout<<n-3<<"UB\n";
}
int main() {
	// your code goes here
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
