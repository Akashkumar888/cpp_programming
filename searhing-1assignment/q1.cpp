#include<iostream>
using namespace std;
int main(){
    int a[]={1,2,2,2,3,3,3,4,4,4,5,5,5};
    int n=sizeof(a)/4;
    int i=0;
    int j=n-1;
    int x;
    cin>>x;
    bool flag=false;
    while(i<=j){
        int mid= i+(j-i)/2;
        if(a[mid]==x){
            if(mid==n-1){
                flag=true;
                cout<<mid;
                break;
            }
       else if(a[mid+1]==x) i=mid+1;
        else{
            flag=true;
         cout<<mid;
         break;
        }
        }
        else if(a[mid]<x) i=mid+1;
        else if(a[mid]>x) j=mid-1;
    }
    if(flag==false) cout<<-1;
    return 0;
}