#include<iostream>
using namespace std;
int main(){
    int a[100];
    int n;
    cout<<"Enter n: ";
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1;j++){
            if(a[i]<a[j]){
                // int temp=a[i];
                // a[i]=a[j];
                // a[j]=temp;

                swap(a[i],a[j]);

                
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}