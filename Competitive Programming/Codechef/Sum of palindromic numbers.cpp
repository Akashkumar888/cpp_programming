#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(int num){

    int original = num;
    int rev = 0;

    while(num){

        rev = rev * 10 + (num % 10);
        num /= 10;
    }

    return original == rev;
}

void solve(){

    int l, r;
    cin >> l >> r;

    long long sum = 0;

    for(int i = l; i <= r; i++){

        if(isPalindrome(i)){
            sum += i;
        }
    }

    cout << sum << "\n";
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
