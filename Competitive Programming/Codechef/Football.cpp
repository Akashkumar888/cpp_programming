#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    // The first line of each test case contains a single integer N

    vector<int>arr(n),brr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n;i++){
        cin>>brr[i];
    }
    int maxNumber=0;
    for(int i=0;i<n;i++){
        if(arr[i]>=0){
            int wt=((arr[i]*20)-(brr[i]*10));
            maxNumber=max(wt,maxNumber);
        }
    }
    cout<<maxNumber<<endl;
}

int main() {
	// your code goes here
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}


// 🔹 2. What You Mean by “at a time” 🤔
// If you mean:
// 👉 Input like this:

// A1 B1
// A2 B2
// A3 B3

// Then you can take both arrays together like this:

// for(int i = 0; i < n; i++){
//     cin >> arr[i] >> brr[i];
// }
