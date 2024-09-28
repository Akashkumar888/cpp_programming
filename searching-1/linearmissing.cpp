#include<iostream>
using namespace std;
int main(){
    int a[]={0,1,2,3,4,5,6,7,8,9,12};
    int n=sizeof(a)/4;

    for(int i=0;i<n-1;i++){
     if(a[i]+1!=a[i+1]){
        cout<<a[i]+1;
        break;
     }
    }
    return 0;
}