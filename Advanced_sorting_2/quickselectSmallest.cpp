#include<iostream>
using namespace std;
int partiotions(int arr[],int st,int ed){
int pivotElement=arr[(st+ed)/2];
int count=0;
for(int i=st+1;i<=ed;i++){
    if(i==(st+ed)) continue; // randomized pivot element
    if(arr[i]<=pivotElement) count++;
}
int pivotidx=st+count;
swap(arr[(st+ed)/2],arr[pivotidx]);
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
int kthSmallest(int arr[],int st,int ed,int k){
    
    int pivotidx=partiotions(arr,st,ed);
    if(k==pivotidx+1) return arr[pivotidx];
    else if(k>pivotidx+1) return kthSmallest(arr,pivotidx+1,ed,k);
   else return kthSmallest(arr,st,pivotidx-1,k);
}
    
int main(){
    int arr[]={9,8,7,6,5,4,3,2,1};
    int n=sizeof(arr)/sizeof(arr[0]);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    int k;
    cin>>k;
    cout<<kthSmallest(arr,0,n-1,k);
    
    return 0;
}