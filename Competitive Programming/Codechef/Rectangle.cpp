#include <bits/stdc++.h>
using namespace std;

void solve(){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    map<int,int>mp;
    mp[a]++;
    mp[b]++;
    mp[c]++;
    mp[d]++;
    for(auto &it:mp){
        if(mp.size()>2 || it.second==1){
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";
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


#include <bits/stdc++.h>
using namespace std;

void solve(){
    vector<int> arr(4);
    for(int i = 0; i < 4; i++) cin >> arr[i];

    sort(arr.begin(), arr.end());

    if(arr[0] == arr[1] && arr[2] == arr[3])
        cout << "YES\n";
    else
        cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
