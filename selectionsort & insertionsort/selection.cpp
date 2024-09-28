#include<iostream>
#include<climits>
using namespace std;
int main(){
    int a[]={5,4,3,2,1};
    for(int i:a){
        cout<<i<<" ";
    }
    cout<<endl;
    int n=sizeof(a)/4;
    for(int i=0;i<n-1;i++){
    int min=INT_MAX;
    int minidx=-1;
        for(int j=i;j<n;j++){
        if(a[j]<min) {
            min=a[j] ;
            minidx=j;
        }
        }
        swap(a[i],a[minidx]);
    }
    for(auto i:a){
        cout<<i<<" ";
    }
    return 0;
}