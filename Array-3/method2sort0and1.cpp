#include<iostream>
#include<vector>
using namespace std;
void sort0and1(vector<int>&v){
    int i=0;
    int j=v.size()-1;
  while(i<j){
    if(v[j]==1) j--;
    if(v[i]==0) i++;
    if(i>j) break;
    if(v[i]==1 && v[j]==0){
        v[i]=0;
        v[j]=1;
    i++;
    j--;
    }
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