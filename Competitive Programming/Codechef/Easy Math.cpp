#include <bits/stdc++.h>
using namespace std;

int digitSum(int n){
    int digits=0;
    while(n>0){
        int rem=n%10;
        digits+=rem;
        n=n/10;
    }
    return digits;
}

void solve(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];
    // sort(arr.begin(),arr.end());
    int maxSum=0;
    // check all pairs
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            long long prod = 1LL * arr[i] * arr[j];
            maxSum = max(maxSum, digitSum(prod));
        }
    }
    cout<<maxSum<<endl;
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
