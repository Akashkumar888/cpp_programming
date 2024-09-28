#include<iostream>
#include<vector>
using namespace std;

vector<vector<char>>grid;
vector<vector<string>>result;
bool check(int row,int col,int n){
// column check
for(int i=row-1;i>=0;i--){
    if(grid[i][col]=='Q') return false;
}
// left diagonal
for(int i=row-1,j=col-1;i>=0 && j>=0;i--,j--){
    if(grid[i][j]=='Q') return false;
}
// right diagonal
for(int i=row-1,j=col+1;i>=0 && j<n;i--,j++){
    if(grid[i][j]=='Q')return false;
}
return true;
}
void f(int row,int n){
if(row==n){
    vector<string>temp;
    for(int i=0;i<n;i++){
        string ans="";
        for(int j=0;j<n;j++){
            ans+=grid[i][j];
        }
        temp.push_back(ans);
    }
    result.push_back(temp);
        return;
}
    for(int col=0;col<n;col++){
        if(check(row,col,n)){
            grid[row][col]='Q';
            f(row+1,n);
            grid[row][col]='.';
        }
    }
}
vector<vector<string>> solveNQueens(int n){
grid.clear();
result.clear();
grid.resize(n,vector<char>(n,'.'));
f(0,n);
return result;
}
int main()
{
    solveNQueens(4);
return 0;
}