#include<iostream>
using namespace std;
int main(){
    int a[]={1,2,3,4,5,6,7,8,9,12};
    int n=sizeof(a)/4;

    for(int i=0;i<n;i++){
     if(i!=a[i]){
        cout<<i;
        break;
     }
    }
    return 0;
}