#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k1;
    cin>>n>>k1;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int total = 1<<n;
    for(int k=1;k<total;k++){
        if(__builtin_popcount(k)==k1){
        for(int i=0;i<n;i++){
            if(k&(1<<i)){
                cout<<arr[i]<<" ";
            }
        }
            cout<<endl;
    }
        }
    return 0;
}