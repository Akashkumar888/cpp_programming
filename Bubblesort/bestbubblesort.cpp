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
        cout<<a[i]<<" ";
    }
    for(int i=0;i<n-1;i++){      // n-1 passes
        // for traverse
       bool flag=true;
        
        for(int j=0;j<n-1-i;j++){ // -i become efficient code
            if(a[j]>a[j+1]){
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
                flag=false;
            }
        }
        if(flag==true) {  // swap did not happen
            break;
        }
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}