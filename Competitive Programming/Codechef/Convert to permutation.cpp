
#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end());
    int countOperation=0;
    // 1 1 2 3
    // 0 1 2 3
    for(int i=0;i<n;i++){
        int need=i+1;
        if(arr[i]>need){
            cout<<"-1"<<endl;
            return ;
        }
        countOperation+=abs(arr[i]-need);
    }
    cout<<countOperation<<endl;
}
int main() {
	// your code goes here
int t;
cin>>t;
while(t--){
    solve();
}
return 0;
}
// always use this format for all problems 
