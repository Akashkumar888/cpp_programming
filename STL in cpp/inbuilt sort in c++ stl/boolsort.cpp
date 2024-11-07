#include<bits/stdc++.h>
using namespace std;
int main(){
    bool a[]={0,1,0,1,1,1,1,0,1,0,1,0,1,0,1};
    int n=sizeof(a)/sizeof(a[0]);
    sort(a,a+n);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}