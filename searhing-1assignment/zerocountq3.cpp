#include<iostream>
using namespace std;
int main(){
    int a[]={0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1};
    int n=sizeof(a)/4;
    int i=0;
    int j=n-1;
    while(i<=j){
        int mid=i+(j-i)/2;
        if(a[mid]==0){
            if(mid==n-1){
             cout<<(mid+1);
             break;
            }
            if(a[mid+1]==0) i=mid+1;
            else{
             cout<<(mid+1);
             break;
            }
        }
        else if(a[mid]<0) i=mid+1;
        else if(a[mid]>0) j=mid-1;
    }
    return 0; 
}