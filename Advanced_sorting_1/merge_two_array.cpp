#include<iostream>
#include<vector>
using namespace std;
void merge(vector<int>&a,vector<int>&b,vector<int>&res){
int i=0;
int j=0;
int k=0;
int m=a.size();
int n=b.size();
while(i<m && j<n){
    if(a[i]<b[j]){
        res[k]=a[i];
        k++;
        i++;
    }
    else {
        res[k]=b[j];
        k++;
        j++;
    }
    if(i==m){
        while(j<n){
            res[k]=b[j];
            k++;
            j++;
        }
    }
    if(j==n){
        while(i<m){
            res[k]=a[i];
            k++;
            i++;
        }
    }
}
}
int main(){
    int arr[]={1,3,5,7};
    int m=sizeof(arr)/sizeof(arr[0]);
    vector<int>a(arr,arr+m);
    int brr[]={2,4,6,8};
    int n=sizeof(brr)/sizeof(brr[0]);
    vector<int>b(brr,brr+n);
    vector<int>res(m+n);
    merge(a,b,res);
for(int i=0;i<res.size();i++){
    cout<<res[i]<<" ";
}
    return 0;
}