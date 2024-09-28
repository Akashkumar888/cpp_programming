#include<iostream>
using namespace std;
int main(){
    int a[]={0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1};
    int n=sizeof(a)/4;
    int i=0;
    int j=n-1;
    int index=-1;
    while(i<=j){
        int mid=i+(j-i)/2;
        if(a[mid]==1){
            if(mid==0){
              index=mid;
             break; 
            }
            if(a[mid-1]==1) j=mid-1;
            else{
             index=mid;
             break;
            }
        }
        else if(a[mid]<1) i=mid+1;
        else if(a[mid]>1) j=mid-1;
    }
    int k=n-index;
    if(index==-1) cout<<0;
    else cout<<n-k;
    return 0; 
}