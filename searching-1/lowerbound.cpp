#include<iostream>
using namespace std;
int main(){
int a[]={1,2,4,5,9,15,18,21,24};
int n=sizeof(a)/4;
int tr=20;
for(int i=0;i<n;i++){
    if(a[i]>tr){
        cout<<a[i-1];
        break;
    }
}
    return 0;
}