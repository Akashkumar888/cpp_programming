#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int max=arr[0];
    int smax=arr[0];
    for(int i=1;i<n;i++){
        if(max<arr[i]){
            max=arr[i];
        }
    }
    cout<<"max: "<<max<<endl;
    for(int i=0;i<n;i++){
        if(arr[i]!=max && smax<arr[i]){
        smax=arr[i];
        }
    }
    cout<<"smax: "<<smax<<endl;
    cout<<"sum: "<<smax+max<<endl;
    return 0;
}