#include<bits/stdc++.h>
using namespace std;
int main() {
    vector<vector<int>> v;
    int row, column, a;
    cin>>row;
        // cin>>column;
    for(int i=0 ; i<row ; i++) {
        cin>>column;
         vector<int> p;
         for(int j=0 ; j<column ; j++) {
              cin>>a;
              p.push_back(a);
         }
         v.push_back(p);
    }
    for(auto q: v) {
        for(auto i: q) {
            cout<<i<<" ";
         } 
         cout<<endl;
     }
      return 0;
}