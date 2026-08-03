
class Solution {
  public:
    int largestArea(int n, int m, vector<vector<int>> &arr) {
        int k = arr.size();
        vector<int> rows;
        vector<int> cols;
        for(auto &it : arr){
            rows.push_back(it[0]);
            cols.push_back(it[1]);
        }
        sort(rows.begin(), rows.end());
        sort(cols.begin(), cols.end());

        int maxRow = 0;
        int maxCol = 0;

        int prevRow = 0;
        // Maximum continuous rows
        for(int i = 0; i < k; i++){
            maxRow = max(maxRow, rows[i] - prevRow - 1);
            prevRow = rows[i];
        }
        
        maxRow = max(maxRow, n - prevRow); // for last row
        int prevCol = 0;

        // Maximum continuous columns
        for(int i = 0; i < k; i++){
            maxCol = max(maxCol, cols[i] - prevCol - 1);
            prevCol = cols[i];
        }
        maxCol = max(maxCol, m - prevCol);// for last column
        
        int maxArea = maxRow * maxCol;

        return maxArea;
    }
};