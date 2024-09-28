#include<iostream>
#include<string>
#include<vector>
using namespace std;
void printsubset(int arr[],int n,int idx,vector<int>&v){
    if(idx==n){
      for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
      }
      cout<<endl;
      return;
    }
    printsubset(arr,n,idx+1,v);
    v.push_back(arr[idx]);
    printsubset(arr,n,idx+1,v);
    v.pop_back();
}
int main(){
   int arr[]={1,2,3};
   int n=sizeof(arr)/sizeof(arr[0]);
    vector<int>v;
   printsubset(arr,n,0,v);
    return 0;
}