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
    if(a[i]<=b[j]){
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
void mergesort( vector<int>&v){
int n=v.size();
int n1=n/2;
int n2=n-n1;
if(n==1) return;
vector<int>a(n1),b(n2);
for(int i=0;i<n1;i++){
    a[i]=v[i];
}
for(int i=0;i<n2;i++){
    b[i]=v[i+n1];
}
mergesort(a);
mergesort(b);
merge(a,b,v);
}
int main(){
    int arr[]={2,5,1,6,3,7,4,9,8,10};
    int n=sizeof(arr)/sizeof(arr[0]);
    vector<int>v(arr,arr+n);
    for(int i=0;i<v.size();i++){
    cout<<v[i]<<" ";
}
    cout<<endl;

    mergesort(v);

for(int i=0;i<v.size();i++){
    cout<<v[i]<<" ";
}
    return 0;
}