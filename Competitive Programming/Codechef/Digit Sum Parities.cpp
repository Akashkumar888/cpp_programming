#include <bits/stdc++.h>
using namespace std;

// 🔹 function to calculate digit sum
int digitSum(int n){
    int sum = 0;
    while(n > 0){
        int rem=n%10;
        sum += rem;
        n = n/10;
    }
    return sum;
}

void solve(){
    int n;
    cin >> n;
    // 🔹 step 1: digit sum of N
    int s1 = digitSum(n);
    // 🔹 step 2: check N+1
    int s2 = digitSum(n + 1);
    // 🔹 if parity different → answer = N+1
    if((s1 % 2) != (s2 % 2)){
        cout << n + 1 << endl;
    }
    else{
        // 🔹 otherwise N+2 will always work
        cout << n + 2 << endl;
    }
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
