#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n,k;
    cin>>n>>k;
    int sum=0;
    while(n--){
        int t,d;
        cin>>t>>d;
        
        if(k>=t){
            k-=t;
        }
        else {
            sum+=((t-k)*d);
            k=0;
        }
    }
    cout<<sum<<"\n";
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
    return 0;
}
