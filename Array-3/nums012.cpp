#include<iostream>
#include<vector>
using namespace std;
void beg(vector<int>&v){
    int no0=0;
    int no1=0;
    int no2=0;
    for(int i=0;i<v.size();i++){
        if(v[i]==0) no0++;
        else if(v[i]==1)  no1++;
        else no2++;
    }
    for(int i=0;i<v.size();i++){
        if(i<no0) v[i]=0;
        else if(i<(no0+no1)) v[i]=1;
        else v[i]=2;
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
    beg(v);
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }
    return 0;
}