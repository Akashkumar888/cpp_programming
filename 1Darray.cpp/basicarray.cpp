#include<iostream>
using namespace std;
int main(){
    int n=5,a[n];
    a[0]=56;
    a[1]=16;
    a[2]=26;
    a[3]=36;
    a[4]=66;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}