#include<iostream>
using namespace std;
int main(){
    int a[]={1,2,3,4,5,6,7,8,9,12};
    int n=sizeof(a)/4;
    int i=0;
    int j=n-1;
        int ans=-1;
    while(i<=j){
        int mid=i+(j-i)/2;
         if(mid==a[mid]) i=mid+1;
         else{
            ans=mid;
            j=mid-1;
         }
    }
    cout<<ans;
    return 0;
}