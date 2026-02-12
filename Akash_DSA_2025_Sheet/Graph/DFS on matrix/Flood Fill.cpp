
class Solution {
public:
int dx[4]={0,1,0,-1};
int dy[4]={-1,0,1,0};
void dfs(int i,int j,int m,int n,vector<vector<int>>& image,int color,int newColor){
 if(i<0 || i>=m || j<0 || j>=n || image[i][j]!=color || image[i][j]==newColor )return;

 image[i][j]=newColor;
 
 for(int k=0;k<4;k++){
    int ni=i+dx[k];
    int nj=j+dy[k];
    dfs(ni,nj,m,n,image,color,newColor);
 }
}
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m=image.size();
        int n=image[0].size();
        dfs(sr,sc,m,n,image,image[sr][sc],color);
        return image;
    }
};


class Solution {
public:
int dx[4]={0,1,0,-1};
int dy[4]={-1,0,1,0};
void bfs(int i,int j,int m,int n,vector<vector<int>>& image,int color,int newColor){
 queue<pair<int,int>>q;
 q.push({i,j});
 while(!q.empty()){
    int x=q.front().first;
    int y=q.front().second;
    q.pop();
    image[x][y]=newColor;
    for(int k=0;k<4;k++){
        int nx=x+dx[k];
        int ny=y+dy[k];
        if(nx>=0 && nx<m && ny>=0 && ny<n && image[nx][ny]==color && image[nx][ny]!=newColor){
            q.push({nx,ny});
        }
    }
 }
}
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m=image.size();
        int n=image[0].size();
        bfs(sr,sc,m,n,image,image[sr][sc],color);
        return image;
    }
};