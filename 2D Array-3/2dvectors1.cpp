#include <iostream> 
#include <vector>  
using namespace std; 
int main() 
{ 
    int n = 4; 
    int m = 5; 
    vector<vector<int>> vec( n , vector<int> (m));  // simple logic 
    // vector<vector<int>> vec( n , vector<int> (m,0));  
    // vector<vector<int>> vec( m , vector<int> (n));  
  
    for(int i = 0; i < n; i++) 
    { 
        for(int j = 0; j < m; j++) 
        { 
            vec[i][j] = j + i + 1; 
        } 
    } 
    for(int i = 0; i < n; i++) 
    { 
        for(int j = 0; j < m; j++) 
        { 
            cout << vec[i][j] << " "; 
        } 
        cout << endl; 
    }   
   return 0; 
} 