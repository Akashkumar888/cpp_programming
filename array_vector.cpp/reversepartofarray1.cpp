#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void reversepart(int i,int j,vector<int>&a){
    while(i<=j){
        int temp=a[i];
        a[i]=a[j];
        a[j]=temp;
        i++;
        j--;
    }
}
void display(vector<int>a){
    for(int i=0;i<a.size();i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
int main(){
    vector<int>v;
    int n;
    cin>>n;
    int t;
    for(int i=0;i<n;i++){
        cin>>t;
        v.push_back(t);
    }
        reversepart(0,4,v);
        display(v);
    return 0;
}