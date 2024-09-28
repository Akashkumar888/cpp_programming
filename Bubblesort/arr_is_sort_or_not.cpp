#include<iostream>
using namespace std;
int main(){
    int a[]={1,2,2,3,4,4,5,5,6,7,7,8,9};
    int n=sizeof(a)/4;
    bool flag=true;
    for(int i=0;i<n-1;i++){
            if(a[i]>a[i+1]){
                flag=false; 
                break;
            }
    }
    if(flag==true) cout<<"sorted";
    else cout<<"Not sorted";
    return 0;
}