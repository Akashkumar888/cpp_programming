#include<iostream>
using namespace std;
void arrtrav(int n,int arr[]){
    if(n==0) return ;
    cout<<arr[n-1]<<" ";
    return arrtrav(n-1,arr);
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
   arrtrav(n,arr);
    return 0;
}