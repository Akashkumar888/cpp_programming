#include <bits/stdc++.h>
using namespace std;

void solve(){

    int n,k;
    cin>>n>>k;

    vector<int>arr(n);

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    vector<int>votes(n+1,0);
    vector<bool>disqualified(n+1,false);

    for(int i=0;i<n;i++){

        votes[arr[i]]++;

        if(arr[i]==i+1){
            disqualified[i+1]=true;
        }
    }

    int count=0;

    for(int student=1;student<=n;student++){

        if(votes[student]>=k &&
           !disqualified[student]){

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
