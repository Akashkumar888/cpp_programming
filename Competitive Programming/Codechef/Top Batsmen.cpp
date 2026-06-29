#include <bits/stdc++.h>
using namespace std;

long long nCr(int n, int r){

    if(r > n) return 0;

    if(r > n - r){
        r = n - r;
    }

    long long ans = 1;

    for(int i = 0; i < r; i++){
        ans = ans * (n - i);
        ans = ans / (i + 1);
    }

    return ans;
}

void solve(){

    vector<int> a(11);

    for(int i = 0; i < 11; i++){
        cin >> a[i];
    }

    int k;
    cin >> k;

    vector<int> b = a;

    sort(b.begin(), b.end(), greater<int>());

    int x = b[k - 1];

    int total = 0;
    int need = 0;

    for(int val : a){
        if(val == x){
            total++;
        }
    }

    for(int i = 0; i < k; i++){
        if(b[i] == x){
            need++;
        }
    }

    cout << nCr(total, need) << "\n";
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
