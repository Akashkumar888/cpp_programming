#include<iostream>
#include<vector>
using namespace std;

vector<int> merge (vector<int>&arr1, vector<int>&arr2){
int i=0;
int j=0;
int k=0;
int m=arr1.size();
int n=arr2.size();
vector<int>res(m+n);
while(i<=m-1 && j<=n-1){
    if(arr1[i]<arr2[j]){
         res[k]=arr1[i];
         i++;
         k++;
    }
    else {
        res[k]=arr2[j];
        j++;
        k++;
    }
}
if(i==m ){
    while(j<=n-1){
 res[k]=arr2[j];
 k++;
 j++;
    }
}
if(j==n ){
    while(i<=m-1){
 res[k]=arr1[i];
 k++;
 i++;
    }
}
return res;
}
int main(){
    
   vector<int>arr1;
   arr1.push_back(1);
   arr1.push_back(2);
   arr1.push_back(3);
   arr1.push_back(4);
   arr1.push_back(11);

   vector<int>arr2;
   arr2.push_back(5);
   arr2.push_back(6);
   arr2.push_back(7);
   arr2.push_back(8);
   arr2.push_back(9);
   arr2.push_back(10);
   vector<int>v=merge(arr1,arr2);
   for(int i=0;i<v.size();i++){
    cout<<v[i]<<" ";
   }
    return 0;
}