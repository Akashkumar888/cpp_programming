#include <bits/stdc++.h>
using namespace std;

bool check(string &s, string &t){
    int n = s.size();
    vector<int> diff;

    for(int i = 0; i < n; i++){
        if(s[i] != t[i]) diff.push_back(i);
    }

    if(diff.empty()) return true;

    int l = diff.front();
    int r = diff.back();

    // try without invert (only reverse)
    bool ok1 = true;
    for(int i = l; i <= r; i++){
        if(s[i] != t[l + r - i]){
            ok1 = false;
            break;
        }
    }

    // try with invert
    bool ok2 = true;
    for(int i = l; i <= r; i++){
        char inv = (s[i] == 'a' ? 'b' : 'a');
        if(inv != t[l + r - i]){
            ok2 = false;
            break;
        }
    }

    return ok1 || ok2;
}

void solve(){
    string s;
    cin >> s;
    int n = s.size();

    string t1 = "", t2 = "";

    for(int i = 0; i < n; i++){
        t1 += (i % 2 == 0 ? 'a' : 'b');
        t2 += (i % 2 == 0 ? 'b' : 'a');
    }

    if(check(s, t1) || check(s, t2))
        cout << "YES\n";
    else
        cout << "NO\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--) solve();
}
