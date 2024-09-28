#include<iostream>
#include<vector>
using namespace std;
void beg(vector<int>&v){
    int lo=0;
    int mid=0;
    int hi=v.size()-1;
    while(mid<=hi){
        if(v[mid]==2){
            int temp=v[mid];
            v[mid]=v[hi];
            v[hi]=temp;
            hi--;
        }
        else if(v[mid]==0){
            int temp=v[mid];
            v[mid]=v[lo];
            v[lo]=temp;
            lo++;
            mid++;
        }
        else {
            mid++;
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
    beg(v);
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }
    return 0;
}