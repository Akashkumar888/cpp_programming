#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>v;
   int x;
   for(int i=0;i<n;i++){
    cin>>x;
    v.push_back(x);
   }
   for(int i=0;i<n;i++){
    cout<<v[i]<<" ";
   }
    return 0;
}