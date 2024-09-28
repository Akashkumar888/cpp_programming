#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int>v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    vector<int>v2;
    v2.push_back(4);
    v2.push_back(5);
    vector<int>v3;
    v3.push_back(6);
    v3.push_back(7);
    v3.push_back(8);
    v3.push_back(9);
    v3.push_back(10);
    vector<vector<int>>v;
    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);

    for(int i=0;i<v.size();i++){       // for row size like int n=v.size();
     for(int j=0;j<v[i].size();j++){   // for column size like int m=v[0].size();
        cout<<v[i][j]<<" ";            // for vector<vector<int>v(m,vector<int>(n));
     }                                 // for vector<vector<int>v(n,vector<int>(m,0));
    cout<<endl;                        // for vector<vector<int>>v(n,vector<int>(m)); 
    }

//     for(int i=0;i<v.size();i++){
//     for(int j=0;j<v[i].size();j++){
//         cout<<v[i][j]<<" ";
//     }
//     cout<<endl;
// }
cout<<endl;
for (vector<int> v1D : v) 
    { 
        for (int x : v1D) 
        { 
            cout << x << " "; 
        }     
        cout << endl; 
    } 
  
    return 0;
}