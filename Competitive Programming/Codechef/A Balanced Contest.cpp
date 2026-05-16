#include <bits/stdc++.h>
using namespace std;

void solve(){

    int n, p;
    cin >> n >> p;

    vector<int> arr(n);

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int cakewalk = 0;
    int hard = 0;
    // exactly 1 cakewalk and exactly 2 hard problems. 
    for(int i = 0; i < n; i++){

        // hard problem
        if(arr[i] <= p / 10){ //at max P / 10 (integer division)
            hard++;
        }

        // cakewalk problem
        if(arr[i] >= p / 2){ //at least half of the participants (i.e. P / 2 (integer division)) 
            cakewalk++;
        }
    }
    if(cakewalk == 1 && hard == 2){
        cout << "yes\n";
    }
    else{
        cout << "no\n";
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
