
#include <bits/stdc++.h>
using namespace std;

void solve(){

    int n;
    cin>>n;

    vector<int>arr(n);

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    vector<int>mark(n,0);

    for(int i=0;i<n-1;i++){

        if(arr[i]!=arr[i+1]){

            mark[i]=1;
            mark[i+1]=1;
        }
    }

    int count=0;

    for(int i=0;i<n;i++){

        if(mark[i]){
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
