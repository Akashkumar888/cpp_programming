#include <bits/stdc++.h>
using namespace std;

void solve(){

    int n;
    cin>>n;

    vector<int>arr(n),drr(n);

    for(int i=0;i<n;i++) cin>>arr[i];

    for(int i=0;i<n;i++) cin>>drr[i];

    map<int,int> mp;

    for(int i=0;i<n;i++){

        mp[arr[i]]++;

        mp[drr[i]]++;
    }

    int maxCount=0;

    for(auto &it:mp){

        maxCount=max(maxCount,it.second);
    }

    cout<<maxCount<<"\n";
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--){
        solve();
    }
}

#include <bits/stdc++.h>
using namespace std;

void solve(){

    int n;
    cin>>n;

    vector<int>arr(n),drr(n);

    for(int i=0;i<n;i++) cin>>arr[i];

    for(int i=0;i<n;i++) cin>>drr[i];

    vector<int>freq(1441,0);

    for(int i=0;i<n;i++){

        freq[arr[i]]++;

        freq[drr[i]]++;
    }

    int maxCount=0;

    for(int i=0;i<=1440;i++){

        maxCount=max(maxCount,freq[i]);
    }

    cout<<maxCount<<"\n";
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--){
        solve();
    }
}
