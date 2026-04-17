#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];
    // odd*odd=odd 
    int oddCount = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] % 2) oddCount++;
    }

    if(oddCount >= 2 && oddCount % 2==0) cout << "YES"<<endl;
    else cout << "NO"<<endl;
}
int main() {
	// your code goes here
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
