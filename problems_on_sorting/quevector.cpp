#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int main(){
    int arr[]={19,12,23,8,16};
    int n=sizeof(arr)/4;
    for(auto i:arr){
        cout<<i<<" ";
    }
    vector<int>v(n,0);
    int x=0;
    for(int i=0;i<n;i++){
        int min=INT_MAX;
        int mindx=-1;
        for(int j=0;j<n;j++){
            if(v[j]==1) continue;
            else {
                if(arr[j]<min){
                    min=arr[j];
                    mindx=j;
                }
            }
        }
        arr[mindx]=x;
        v[mindx]=1;
        x++;
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}