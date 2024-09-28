#include<iostream>
using namespace std;
int main(){
    int a[]={5,0,1,2,0,0,4,0,3};
    int n=sizeof(a)/4;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    for(int i=0;i<n-1;i++){      
        for(int j=0;j<n-1-i;j++){ 
            if(a[j]==0){
                swap(a[j],a[j+1]);
            }
        }
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}