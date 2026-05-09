#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n,k;
    cin>>n>>k;
    vector<int>weights(n);
    for(int i=0;i<n;i++)cin>>weights[i];
    int count=1;
    int sum=0;
    for(int &num:weights){
        if(num>k){
            cout<<-1<<"\n";
            return;
        }
        sum+=num;
        if(sum>k){
            count++;
            sum=num;
        }
    }
    cout<<count<<"\n";
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
