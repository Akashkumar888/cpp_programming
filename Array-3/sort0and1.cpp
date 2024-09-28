#include<iostream>
#include<vector>
using namespace std;
void sort0and1(vector<int>&v){
  int  n=v.size();
int no0=0;
int no1=0;
for(int i=0;i<n;i++){
    if(v[i]==1) no1++;
    else no0++;
}
for(int i=0;i<n;i++){
    if(i<no0) v[i]=0;
    else v[i]=1;
}
}
int main(){
    vector<int>v;
    int n;
    cin>>n;
    int x;
    for(int i=0;i<n;i++){
        cin>>x;
        v.push_back(x);
    }
    sort0and1(v);
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }
    return 0;
}