#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int>v{0,1,2,3,4};
//    for(int i=0;i<v.size()-1;i++){
//     for(int j=i+1;j<v.size();j++){
//     swap(v[i],v[j]);
//     }
//    }  
// all element in reverse

 int i=2,j=3; // i and j element
   swap(v[i],v[j]);
    for(auto i:v){
        cout<<i<<" ";
    }
    return 0;
}