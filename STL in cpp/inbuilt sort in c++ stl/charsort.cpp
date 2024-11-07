#include<bits/stdc++.h>
using namespace std;
int main(){
    char a[]={'s','n','a','f','t','e','i','q'};
    int n=sizeof(a)/sizeof(a[0]);
    sort(a,a+n);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}