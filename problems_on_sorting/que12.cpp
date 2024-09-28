#include<iostream>
#include<climits>
using namespace std;
int main(){
    int a[]={19,12,45,23,8,16,33};
    int n=sizeof(a)/4;
        int k=0;
        for(int j=0;j<n;j++){
        int min=INT_MAX;
        int minidx=-1;
            if(a[j]<min){
                min=a[j];
                minidx=j;
            }
            a[minidx]=k;
             cout<<a[minidx]<<" ";
            k++;
        }
        cout<<endl;
    return 0;
}