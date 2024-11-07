#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
int t;
cin>>t;
while(t--){
    int n,m;
    cin>>n>>m;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int total=1<<n;
    bool flag=false;
    for(int k=1;k<total;k++){
        int sum=0;
        for(int i=0;i<n;i++){
            if(k&(1<<i)){
                sum+=arr[i];
            }
        }
        if(sum==m){
            flag=true;
            break;
        }
    }
    if(flag==true) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
}