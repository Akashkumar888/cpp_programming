#include<iostream>
using namespace std;
int main(){
    int a[]={5,4,3,2,1};
    for(auto i:a) cout<<i<<" ";
    cout<<endl;
    int n=sizeof(a)/4;
    for(int i=1;i<n;i++){
    int j=i;
    while(j>=1){
        if(a[j]>=a[j-1]) break;
        if(a[j]<a[j-1]){
            swap(a[j],a[j-1]);
            j--;
        }
    }
    }
    for(auto i:a){
        cout<<i<<" ";
    }
    return 0;
}