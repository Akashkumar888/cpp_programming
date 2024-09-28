#include<iostream>
using namespace std;
int partiotions(int arr[],int st,int ed){
int pivotElement=arr[st];
int count=0;
for(int i=st+1;i<=ed;i++){
    if(arr[i]<=pivotElement) count++;
}
int pivotidx=st+count;
swap(arr[st],arr[pivotidx]);
int i=st;
int j=ed;
while(i<pivotidx && pivotidx<j){
    if(arr[i]<=pivotElement) i++;
    if(arr[j]>pivotElement) j--;
    else if(arr[i]>pivotElement && arr[j]<=pivotElement){
        swap(arr[i],arr[j]);
        i++;
        j--;
}
}
return pivotidx;
}
void quicksort(int arr[],int st,int ed){
    if(st>=ed) return;
    int pivotidx=partiotions(arr,st,ed);

    quicksort(arr,st,pivotidx-1);
    quicksort(arr,pivotidx+1,ed);
}
int main(){
    int arr[]={9,8,7,6,5,4,3,2,1};
    int n=sizeof(arr)/sizeof(arr[0]);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    quicksort(arr,0,n-1);
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}