#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
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
     display(v);
    // int i=0;
    // int j=n-1;
    // while(i<=j){
    //     int temp=v[i];
    //     v[i]=v[j];
    //     v[j]=temp;
    //     i++;
    //     j--;
    // }

    for(int i=0,j=n-1;i<=j;i++,j--){
         int temp=v[i];
        v[i]=v[j];
        v[j]=temp;
    }
        display(v);
    return 0;
}