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
    int *ptr=lower_bound(a,a+n,5);
    cout<<*ptr<<endl;
    cout<<endl;
    int *ptr1=lower_bound(a,a+n,6);
    cout<<*ptr1<<endl;
    return 0;
}