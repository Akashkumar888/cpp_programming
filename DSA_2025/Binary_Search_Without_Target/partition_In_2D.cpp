// jb bhi l or r ko mid pe le ja ya jay to while loop me while(l<r) hi rahta hai
int partition(int l,int r,int n,vector<vector<int>>&mat){
      while(l<r){
          int mid=l+(r-l)/2;
          int row=mid/n;
          int col=mid%n;
          if(mat[row][col]>mat[r/n][r%n]){
              l=mid+1;
          }
          else r=mid;
      }
      return r;
  }
  