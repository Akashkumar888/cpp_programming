
class Solution {
  public:
    int findCoverage(vector<vector<int>>& mat) {

        int n = mat.size();
        int m = mat[0].size();

        int sum = 0;

        for(int i = 0; i < n; i++) {

            for(int j = 0; j < m; j++) {

                if(mat[i][j] != 0){
                    continue;
                }

                int coverage = 0;

                // left
                for(int c = j - 1; c >= 0; c--) {

                    if(mat[i][c] == 1) {
                        coverage++;
                        break;
                    }
                }

                // right
                for(int c = j + 1; c < m; c++) {

                    if(mat[i][c] == 1) {
                        coverage++;
                        break;
                    }
                }

                // up
                for(int r = i - 1; r >= 0; r--) {

                    if(mat[r][j] == 1) {
                        coverage++;
                        break;
                    }
                }

                // down
                for(int r = i + 1; r < n; r++) {

                    if(mat[r][j] == 1) {
                        coverage++;
                        break;
                    }
                }

                sum += coverage;
            }
        }

        return sum;
    }
};