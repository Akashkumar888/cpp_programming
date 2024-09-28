#include<iostream>
using namespace std;
void unique_element(int arr[],int n){
    int res=0;
    for(int i=0;i<n;i++){
        res=res^arr[i];
    }
    int temp=res;
    int k=0;
    while(true){
        if((temp & 1)==1) break;
        k++;
    }
    int retval=0;
    for(int i=0;i<n;i++){
       int num=arr[i];
       if(( (num>>k) & 1)==1) retval^=num;
    }
    cout<<retval<<" ";
    res=retval^res;
    cout<<res<<endl;
}
int main(){
    int arr[]={1,1,3,6,2,3,2,6,7,9,7,4,8,4};
    int n=sizeof(arr)/sizeof(arr[0]);
   unique_element(arr,n);
    return 0;
}