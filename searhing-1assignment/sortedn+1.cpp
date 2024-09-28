#include<iostream>
using namespace std;
int main(){
    int a[]={1,1,2,3,4,5,6,7};
    int n=sizeof(a)/4;
    int l=0;
    int h=n-1;
    bool flag=false;
    while(l<=h){
        int mid=l+(h-l)/2;

        if(a[mid]==mid+1) l=mid+1;

        else if(a[mid]==mid){
        if(a[mid]==a[mid-1]){
            flag=true;
            cout<<a[mid];
            break;
        }
        else h=mid-1;
        }
    // else if(a[mid]<mid+1) l=mid+1;
    // else if(a[mid]>mid+1) h=mid-1;
    }
    if(flag==false) cout<<"Not repeat";

return 0;
}