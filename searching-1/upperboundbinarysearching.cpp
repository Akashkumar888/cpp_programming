#include<iostream>
using namespace std;
int main(){
int a[]={1,2,4,5,9,15,18,21,24};
int n=sizeof(a)/4;
int i=0;
int j=n-1;
int tr=20;
bool flag=false;
while(i<=j){
int mid=i+(j-i)/2;
if(a[mid]==tr){
    flag=true;
 cout<<a[mid+1];
 break;
}
else if(a[mid]<tr) i=mid+1;
else if(a[mid]>tr) j=mid-1;
}
if(flag==false) cout<<"upperbound: "<<a[i];
    return 0;
}