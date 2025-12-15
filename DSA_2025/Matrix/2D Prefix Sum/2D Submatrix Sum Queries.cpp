
class Solution {
  public:
//   (r1, c1) is the top-left coordinate of the submatrix
// (r2, c2) is the bottom-right coordinate of the submatrix (both inclusive)
    vector<int> prefixSum2D(vector<vector<int>> &mat, vector<vector<int>> &queries) {
        // code here
        vector<int>result;
        int n=mat.size();
        int m=mat[0].size();
        for(auto &que:queries){
            int r1=que[0];
            int c1=que[1];
            int r2=que[2];
            int c2=que[3];
            int sum=0;
            for(int i=r1;i<=r2;i++){
                for(int j=c1;j<=c2;j++){
                    sum+=mat[i][j];
                }
            }
            result.push_back(sum);
        }
        return result;
    }
};


class Solution {
  public:
// (r1, c1) is the top-left coordinate of the submatrix
// (r2, c2) is the bottom-right coordinate of the submatrix (both inclusive)
    vector<int> prefixSum2D(vector<vector<int>> &mat, vector<vector<int>> &queries) {
        // code here
        vector<int>result;
        int n=mat.size();
        int m=mat[0].size();
        // -------- BUILD 2D PREFIX SUM --------
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){

                // sum from top cell
                int top = (i - 1 >= 0) ? mat[i - 1][j] : 0;

                // sum from left cell
                int left = (j - 1 >= 0) ? mat[i][j - 1] : 0;

                // sum from diagonal cell (overlap area)
                int diag = (i - 1 >= 0 && j - 1 >= 0) ? mat[i - 1][j - 1] : 0;

                /*
                 Prefix sum formula:
                 mat[i][j] = original value
                              + top
                              + left
                              - diag

                 WHY - diag?
                 Because top and left both include diagonal area,
                 so diagonal gets added twice → subtract once
                */
                mat[i][j] += top + left - diag;
            }
        }

1   2   3   4
2   4   6   8
3   6   9  12
4   8  12  16

9 - 3 - 3 + 1// do bar minus horizontal and vertical ki vajah se isliye ek bar add kr do.


                // -------- ANSWER QUERIES --------
        for(auto &q : queries){

            int r1 = q[0], c1 = q[1];
            int r2 = q[2], c2 = q[3];

            // Start with total sum till (r2, c2)
            int sum = mat[r2][c2];

            // Remove extra top area
            if(r1 - 1 >= 0)
                sum -= mat[r1 - 1][c2];

            // Remove extra left area
            if(c1 - 1 >= 0)
                sum -= mat[r2][c1 - 1];

            /*
             WHY ADD BACK?
             Because top and left subtraction both removed
             the (r1-1, c1-1) area twice.
             So add it once.
            */
            if(r1 - 1 >= 0 && c1 - 1 >= 0)
            sum += mat[r1 - 1][c1 - 1];

            result.push_back(sum);
        }

        return result;
    }
};
