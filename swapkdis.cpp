
#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<int>arr={1,2,3,4,5,6,7};
    int k;
    cout<<"Enter k:";
    cin>>k;
    int n=arr.size();
    if(k>n)k=k%n;
    int i=0,j=n-k-1;
    while(i<j){
        swap(arr[i],arr[j]);
        i++,j--;
    }
    i=n-k,j=n-1;
    while(i<j){
        swap(arr[i],arr[j]);
        i++,j--;
    }
    i=0,j=n-1;
    while(i<j){
        swap(arr[i],arr[j]);
        i++,j--;
    }
    for(auto &it:arr){
        cout<<it<<" ";
    }
return 0;
}