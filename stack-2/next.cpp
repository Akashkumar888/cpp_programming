
#include<iostream>
#include<vector>
using namespace std;
int main(){
   int v[]={3,1,2,5,4,6,2,3};
    int n=sizeof(v)/sizeof(v[0]);
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }
    int nge[n];
    for(int i=0;i<n;i++){
        nge[i]=-1;
        for(int j=i+1;j<n;j++){
            if(v[i]<=v[j]){
              nge[i]=v[j];
              break;
            }
        }
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<nge[i]<<" ";
    }
    return 0;
}