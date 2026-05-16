#include <bits/stdc++.h>
using namespace std;

void solve(){
    string s;
    cin>>s;
    unordered_map<char,int>mp;
    for(char &ch:s)mp[ch]++;
    int count=0;
    for(auto &it:mp){
        count+=(it.second+2-1)/2;
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

#include <bits/stdc++.h>
using namespace std;

void solve(){
    string s;
    cin>>s;
    vector<int>mp(128,0);
    for(char &ch:s)mp[ch]++;
    int count=0;
    for(int i=0;i<128;i++){
        count+=(mp[i]+2-1)/2;
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


#include <bits/stdc++.h>
using namespace std;

void solve(){

    string s;
    cin >> s;

    unordered_set<char> st;

    for(char ch : s){

        // pair completed
        if(st.count(ch)){
            st.erase(ch);
        }
        else{
            st.insert(ch);
        }
    }

    int cost = 0;

    // every pair contributes 1 payment
    // every remaining single contributes 1 payment

    for(char ch : s){
        if(ch){
            cost++;
        }
    }

    cout << (s.size() + st.size()) / 2 << "\n";
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        solve();
    }
}

