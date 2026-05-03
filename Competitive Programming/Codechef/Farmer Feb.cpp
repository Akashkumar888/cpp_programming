#include <bits/stdc++.h>
using namespace std;

// check prime
bool isPrime(int n){
    if(n < 2) return false;
    for(int i = 2; i * i <= n; i++){
        if(n % i == 0) return false;
    }
    return true;
}

void solve(){
    int x,y;
    cin >> x >> y;

    int sum = x + y;

    int k = 1;
    while(true){
        if(isPrime(sum + k)){
            cout << k << "\n";
            return;
        }
        k++;
    }
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
