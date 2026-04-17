#include <bits/stdc++.h>
using namespace std;

bool isSorted(vector<int>& arr) {
    int n=arr.size();
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i+1]) return false;
    }
    return true;
}

void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];

    // already sorted
    if(isSorted(arr)){
        cout << "YES"<<endl;
        return;
    }
    // find first violation
    for(int i = 0; i < n-1; i++){
        if(arr[i] > arr[i+1]){
            swap(arr[i], arr[i+1]);
            break;
        }
    }
    if(isSorted(arr)) cout << "YES"<<endl;
    else cout << "NO"<<endl;
}

int main() {
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
