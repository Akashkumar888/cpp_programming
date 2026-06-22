#include <bits/stdc++.h>
using namespace std;

void solve(){

    int w;
    string s;

    cin >> w >> s;

    vector<int> days(7, 4);

    map<string,int> mp = {
        {"mon",0},
        {"tues",1},
        {"wed",2},
        {"thurs",3},
        {"fri",4},
        {"sat",5},
        {"sun",6}
    };

    int extra = w - 28;

    int start = mp[s];

    for(int i = 0; i < extra; i++){
        days[(start + i) % 7]++;
    }

    for(int i = 0; i < 7; i++){
        cout << days[i] << " ";
    }

    cout << "\n";
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}
