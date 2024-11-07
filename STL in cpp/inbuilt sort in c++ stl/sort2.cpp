#include<bits/stdc++.h>
using namespace std;
int main(){
    int a[]={9,8,7,6,5,4,3,2,1};
    int n=sizeof(a)/4;
    sort(a+2,a+6);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}