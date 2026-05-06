#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;

    vector<int> arr(n);

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    unordered_set<int> inside;

    int maxPeople = 0;

    for(int &id : arr){

        // if already inside -> leave
        if(inside.find(id)!=inside.end()){
            inside.erase(id);
        }
        else{
            // enter
            inside.insert(id);
        }

        maxPeople = max(maxPeople, (int)inside.size());
    }

    cout << maxPeople << "\n";
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

#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];
    map<int,int>mp;
    int maxPeople=0;
    for(int &num:arr){
        if(mp.find(num)!=mp.end()){
            mp[num]--;
            if(mp[num]==0)mp.erase(num);
        }
        else mp[num]++;
        int sz=mp.size();
        maxPeople=max(maxPeople,sz);
    }
    cout<<maxPeople<<"\n";
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
