#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    unordered_map<char,int>mp;
    for(char &ch:s)mp[ch]++;
    for(auto &it:mp){
        if(it.second%2!=0){
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
}
int main() {
	// your code goes here
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
    string s;
    cin>>s;
    vector<int>mp(26,0);
    for(char &ch:s)mp[ch-'a']++;
    for(int i=0;i<26;i++){
        if(mp[i]%2!=0){
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
}
int main() {
	// your code goes here
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
