#include<iostream>
#include<vector>
using namespace std;
int c=0;
int inversion(vector<int>&a,vector<int>&b){
    int count=0;
    int i=0,j=0;
    while(i<a.size() && j<b.size()){
        if(a[i]>b[j]){
            count+=(a.size()-i);
            j++;
        }
        else {
            i++;
        }
    }
    return count;
}
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
void mergesort(vector<int>&v){
int n=v.size();
int n1=n/2;
int n2=n-n/2;
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
c+=inversion(a,b);
merge(a,b,v);
a.clear();// for improving space complexity
b.clear();
}
int main(){
    int arr[]={5,1,3,0,4,9,6};
    int n=sizeof(arr)/sizeof(arr[0]);
    vector<int>v(arr,arr+n);
    for(int i=0;i<v.size();i++){
    cout<<v[i]<<" ";
}
    cout<<endl;

    mergesort(v);

cout<<c;
    return 0;
}