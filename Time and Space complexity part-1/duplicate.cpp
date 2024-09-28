#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int>v={6,3,2,4,1,7,1,5}; 
    int n=v.size();
    vector<int>v1(n,0);
    int count=0;
    for(int i=0;i<n;i++){
       if(v1[(v[i])]==0) v1[(v[i])]=1;
       else cout<<v[i]<<endl;
       count++;
    }
    cout<<count; // no fo operations
    return 0;
}