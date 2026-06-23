#include <bits/stdc++.h>
using namespace std;

void solve(){

    int n;
    cin >> n;

    vector<long long> a(n);

    long long sum = 0;

    for(int i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];
    }

    if(sum % n != 0){
        cout << "Impossible\n";
        return;
    }

    long long mean = sum / n;

    for(int i = 0; i < n; i++){

        if(a[i] == mean){
            cout << i + 1 << "\n";
            return;
        }
    }

    cout << "Impossible\n";
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
