#include<iostream>
#include<vector>
using namespace std;
void combination(int arr[],vector<int>v,int n,int target){
    if(target==0){
        for(int i=0;i<v.size();i++){
            cout<<v[i]<<" ";
        }
        cout<<endl;
        return ;
    }
    if(target<0) return;
    for(int i=0;i<n;i++){
        v.push_back(arr[i]);
        combination(arr,v,n,target-arr[i]);
        v.pop_back();
    }
}
int main(){
    int arr[]={2,3,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    vector<int>v;
    int target=8;
    combination(arr,v,n,target);
    return 0;
}