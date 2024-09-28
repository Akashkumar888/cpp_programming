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
// void reversefull(vector<int>&a){
//     for(int i=0,j=a.size()-1;i<=j;i++,j--){
//         int temp=a[i];
//         a[i]=a[j];
//         a[j]=temp;
//     }
// }
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
    int k;
    cout<<"Enter no of rotation: ";
    cin>>k;
        display(v);
        if(k>=n) k=k%n;
        reversepart(0,n-k-1,v);
        reversepart(n-k,n-1,v);
        reversepart(0,n-1,v);
        display(v);
    return 0;
}