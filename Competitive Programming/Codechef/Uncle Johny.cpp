#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    
    int k;
    cin >> k;
    
    int johny = arr[k - 1];  // Uncle Johny's length
    
    int count = 0;
    
    for(int i = 0; i < n; i++){
        if(arr[i] < johny) count++;
    }
    
    cout << count + 1 << endl;
}

int main() {
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
