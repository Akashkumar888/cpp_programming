
#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>>directions{{1,2},{1,-2},{-1,-2},{-1,2},{2,1},{2,-1},{-2,1},{-2,-1}};
bool isSafe(vector<vector<int>>&grid,int i,int j,int n){
return i>=0&&j>=0&&i<n&&j<n&&grid[i][j]==-1;
}
void display(vector<vector<int>>&grid,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<grid[i][j]<<"\t";
        }
        cout<<endl;
    }
}
void f(vector<vector<int>>&grid,int i,int j,int n,int count){

if(count==n*n-1){
    grid[i][j]=count;
    display(grid,n);
    cout<<"*****"<<endl;
    grid[i][j]=-1;
    return;
}

for(auto &dir:directions){
    int new_i=i+dir[0];
    int new_j=j+dir[1];
    if(isSafe(grid,new_i,new_j,n)){
    grid[i][j]=count;
    f(grid,new_i,new_j,n,count+1);
    grid[i][j]=-1;
    }
}
}
void Kinightstour(int n,int i,int j){
    vector<vector<int>>grid(n,vector<int>(n,-1));
    f(grid,i,j,n,0);
}
int main()
{
Kinightstour(5,0,0);
return 0;
}