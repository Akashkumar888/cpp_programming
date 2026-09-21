
class Solution {
  public:
    int maxArea(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        // height[j] = consecutive 1s ending at current row
        vector<int> height(m, 0);
        int maxArea = 0;
        for(int i = 0; i < n; i++){

            // Build histogram heights
            for(int j = 0; j < m; j++){
                if(mat[i][j] == 1){
                    height[j]++;
                }
                else{
                    height[j] = 0;
                }
            }
            // Copy current heights
            vector<int> temp = height;
            // Since columns can be swapped,
            // arrange maximum heights together
            sort(temp.rbegin(), temp.rend());

            // Calculate maximum rectangle
            for(int j = 0; j < m; j++){
                int width = j + 1;
                int area = temp[j] * width;

                maxArea = max(maxArea, area);
            }
        }
        return maxArea;
    }
};