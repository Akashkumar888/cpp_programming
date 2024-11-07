#include<bits/stdc++.h>
using namespace std;
int main(){
    int a[]={4,5,5,25,7,8};
    int n=sizeof(a)/4;
    sort(a,a+n);
    for(auto i:a){
        cout<<i<<" ";
    }
    cout<<endl;
    int *ptr=lower_bound(a,a+n,26);
    if(ptr==a+n){
        cout<<"Not found";
        return 0;
    }
    cout<<*ptr<<endl;
    return 0;
}