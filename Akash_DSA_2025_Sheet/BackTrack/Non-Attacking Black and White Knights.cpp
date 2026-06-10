
class Solution {
  public:
    // (1,2),(1,-2),(-1,2),(-1,-2)
    // (2,1),(2,-1),(-2,1),(-2,-1)

    int dx[8]={1,1,-1,-1,2,2,-2,-2};
    int dy[8]={2,-2,2,-2,1,-1,1,-1};

    int numOfWays(int n, int m) {
        long long ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int attacks=0;
                for(int k=0;k<8;k++){
                    int nx=i+dx[k];
                    int ny=j+dy[k];
                    if(nx>=0 && nx<n && ny>=0 && ny<m){
                        attacks++;
                    }
                }
                // total cells - attacking positions
                ans += (1LL*n*m - 1 - attacks);
            }
        }
        return ans;
    }
};
// Logic
// For every cell (i,j) where the black knight is placed:
// Total possible positions for the white knight = n*m - 1
// (can't be on the same cell)
// Subtract all cells attacked by the black knight.
// Add remaining valid positions to the answer.
// Since knights are colored (black and white), (A,B) and (B,A) are different arrangements, so no division by 2 is needed.