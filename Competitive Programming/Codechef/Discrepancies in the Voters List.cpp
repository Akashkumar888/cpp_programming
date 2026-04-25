#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n1,n2,n3;
    cin>>n1>>n2>>n3;

    unordered_map<int,int> freq;
    int x;

    // list 1
    for(int i=0;i<n1;i++){
        cin>>x;
        freq[x]++;
    }

    // list 2
    for(int i=0;i<n2;i++){
        cin>>x;
        freq[x]++;
    }

    // list 3
    for(int i=0;i<n3;i++){
        cin>>x;
        freq[x]++;
    }

    vector<int> result;

    for(auto &it : freq){
        if(it.second >= 2){
            result.push_back(it.first);
        }
    }

    sort(result.begin(), result.end());

    cout<<result.size()<<endl;
    for(int &num: result){
        cout<<num<<endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
