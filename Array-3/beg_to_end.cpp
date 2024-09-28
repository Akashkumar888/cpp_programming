#include<iostream>
#include<vector>
using namespace std;
void beg(vector<int>&v){
    int i=0;
    int n=v.size();
    int j=n-1;
 while(i<j){
        if(v[i]<0) i++;
        if(v[j]>0) j--;
        if(i>j) break;
        if(v[i]>0 && v[j]<0){
            int temp=v[i];
            v[i]=v[j];;
            v[j]=temp;
        }
        i++;
        j--;
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