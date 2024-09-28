#include<iostream>
#include<climits>
using namespace std;
int main(){
    int a[]={19,12,23,8,16};
    int n=sizeof(a)/4;
    for(int i=0;i<n;i++){
        int min=INT_MAX;
        int minidx=-1;
        for(int j=i;j<n;j++){
            if(a[j]<min){
                min=a[j];
                minidx=j;
            }
            a[minidx]=i;
        }
    }
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}