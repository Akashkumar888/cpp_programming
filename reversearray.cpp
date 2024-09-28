
#include<iostream>
using namespace std;
int main()
{
    int a[]={1,2,3,4,5,6,7};
    int n=sizeof(a)/sizeof(a[0]);
    int i=0,j=n-1;
    while(i<n/2){
    //    int temp=a[i];
    //    a[i]=a[j];
    //    a[j]=temp;
    swap(a[i],a[j]);
       i++,j--;
    }
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
return 0;
}