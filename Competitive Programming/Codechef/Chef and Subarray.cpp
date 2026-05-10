#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];
    int maxLength=0;
    int count=0;
    for(int &num:arr){
        if(num!=0)count++;
        else{
            maxLength=max(maxLength,count);
            count=0;
        }
    }
    maxLength=max(maxLength,count);
    cout<<maxLength<<"\n";
}
int main() {
	// your code goes here
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
