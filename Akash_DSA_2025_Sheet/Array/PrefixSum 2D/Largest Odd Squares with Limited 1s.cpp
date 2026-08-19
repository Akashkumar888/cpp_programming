
class Solution {
public:
    // Returns the sum of the rectangle:
    // (r1, c1) -> (r2, c2)
    int getSum(vector<vector<int>>& prefix,int r1, int c1, int r2, int c2) {
        int sum = prefix[r2][c2];
        if (r1 > 0) sum -= prefix[r1 - 1][c2];

        if (c1 > 0) sum -= prefix[r2][c1 - 1];

        if (r1 > 0 && c1 > 0) sum += prefix[r1 - 1][c1 - 1];
        return sum;
    }
    vector<int> largestSquare(vector<vector<int>>& mat,vector<vector<int>>& queries,int k) {
        int n = mat.size();
        int m = mat[0].size();
        vector<int> ans;
        // -------------------------------
        // Step 1: Build 2D Prefix Sum
        // -------------------------------
        vector<vector<int>> prefix(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                prefix[i][j] = mat[i][j];
                if (i > 0) prefix[i][j] += prefix[i - 1][j];
                if (j > 0) prefix[i][j] += prefix[i][j - 1];
                if (i > 0 && j > 0) prefix[i][j] -= prefix[i - 1][j - 1];
            }
        }
        // -------------------------------
        // Step 2: Process every query
        // -------------------------------
        for (auto& query : queries) {
            int r = query[0];
            int c = query[1];
            // If the starting cell itself contains 1
            // and we are not allowed to include any 1.
            if (mat[r][c] == 1 && k == 0) {
                ans.push_back(-1);
                continue;
            }
            int x = 1;
            while (true) {
                // Four corners of the square
                int top    = r - x;
                int bottom = r + x;
                int left   = c - x;
                int right  = c + x;
                // Square is outside matrix
                if (top < 0 || bottom >= n ||
                    left < 0 || right >= m) {
                    break;
                }

                // Number of 1s inside the square
                int ones = getSum(prefix, top, left, bottom, right);

                // Cannot expand further
                if (ones > k) break;

                x++;
            }
            // x is the first invalid radius.
            // Therefore valid radius = x - 1.
            // Side length = 2 * radius + 1
            int side = 2 * (x - 1) + 1;
            ans.push_back(side);
        }
        return ans;
    }
};

