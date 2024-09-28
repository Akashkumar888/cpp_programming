#include <iostream> 
#include <vector>  
using namespace std; 
int main() 
{ 
    vector<vector<int>>v(3,vector<int>(7,6));
    int m=v.size();
    int n=v[2].size(); // v[0] v[1] v[2] rows 3 hai aur index start from 0 to 1 to 2 hai 
    cout<<m<<" "<<n;
    cout<<endl;

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
        cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }

    // for(auto i:v){
    //     for(auto x:i){
    //      cout<<x<<" ";
    //     }
    //     cout<<endl;
    // }
   return 0; 
} 