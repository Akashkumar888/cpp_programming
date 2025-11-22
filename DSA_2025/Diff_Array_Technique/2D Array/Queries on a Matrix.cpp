
class Solution {
public:
    vector<vector<int>> solveQueries(int n, vector<vector<int>> Queries) {
        // diff is (n+1) x (n+1) so r2+1 and c2+1 are always safe (they can equal n)
        vector<vector<int>> diff(n, vector<int>(n, 0));
        for (auto &q : Queries) {
            int r1 = q[0], c1 = q[1];
            int r2 = q[2], c2 = q[3];
            // apply 1D range update for every row in [r1, r2]
            for (int r = r1; r <= r2; ++r) {
                diff[r][c1] += 1;
                diff[r][c2 + 1] -= 1; // c2+1 is <= n, diff has n+1 columns
            }
        }
        for(int i=0;i<n;i++){
            for(int j=1;j<n;j++){
                diff[i][j]+=diff[i][j-1];
            }
        }
        return diff;
    }
};
// # class Solution:
// #     def solveQueries(self, n, Queries):
// #         # diff: n rows, n columns (same as your C++ code)
// #         diff = [[0] * n for _ in range(n)]

// #         # apply 1D difference on each affected row
// #         for r1, c1, r2, c2 in Queries:
// #             for r in range(r1, r2 + 1):
// #                 diff[r][c1] += 1
// #                 if c2 + 1 < n:
// #                     diff[r][c2 + 1] -= 1

// #         # prefix sum on each row
// #         for i in range(n):
// #             for j in range(1, n):
// #                 diff[i][j] += diff[i][j - 1]

// #         return diff
