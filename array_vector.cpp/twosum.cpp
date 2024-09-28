#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int x;
    cout<<"Enter target: ";
    cin>>x;
    vector<int>v;
   int n;
   cout<<"Enter size of vector: ";
   cin>>n;
   int p;
   cout<<"Enter vector element: ";
   for(int i=0;i<n;i++){
    cin>>p;
    v.push_back(p);
   }
   for(int i=0;i<n-1;i++){
    for(int j=i+1;j<n;j++){
        if(v[i]+v[j]==x){
            cout<<"("<<i<<","<<j<<")"<<endl;
        }
    }
   }
    return 0;
}