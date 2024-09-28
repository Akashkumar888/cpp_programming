#include<iostream>
#include<vector>
using namespace std;
int main(){
    int arr[]={0,-1,-2,3,4,-5,6,4,7,-8};
    int n=sizeof(arr)/sizeof(arr[0]);
    int k=3;
    vector<int>ans;
    for(int i=0;i<n;i++){
        for(int j=0;j<k;j++){
            if(arr[i+j]<0){
                ans.push_back(arr[i+j]);
                break;
            }
        }
        // for(int j=0;j<k;j++){
        //     if(arr[i+j]>0){
        //         ans.push_back(0);
        //         break;
        //     }
        // }
    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}