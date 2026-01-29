
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    typedef pair<int, pair<int, int>> P;
    vector<vector<int>> directions = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};

    int trapRainWater(vector<vector<int>>& height) {
        int m = height.size();
        int n = height[0].size();
        priority_queue<P, vector<P>, greater<P>> pq;
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        // Add boundary cells to the priority queue
        for (int i = 0; i < m; i++) {
            pq.push({height[i][0], {i, 0}});
            pq.push({height[i][n - 1], {i, n - 1}});
            visited[i][0] = true;
            visited[i][n - 1] = true;
        }
        for (int j = 1; j < n - 1; j++) {
            pq.push({height[0][j], {0, j}});
            pq.push({height[m - 1][j], {m - 1, j}});
            visited[0][j] = true;
            visited[m - 1][j] = true;
        }

        int water = 0;

        // Process cells in priority queue
        while (!pq.empty()) {
            int ht = pq.top().first;
            int i = pq.top().second.first;
            int j = pq.top().second.second;
            pq.pop();

            for (auto& dir : directions) {
                int new_i = i + dir[0];
                int new_j = j + dir[1];

                if (new_i >= 0 && new_i < m && new_j >= 0 && new_j < n && !visited[new_i][new_j]) {
                    visited[new_i][new_j] = true;

                    // Calculate trapped water
                    water += max(0, ht - height[new_i][new_j]);

                    // Update height for the next layer
                    int newh = max(ht, height[new_i][new_j]);
                    pq.push({newh, {new_i, new_j}});
                }
            }
        }

        return water;
    }
};

int main() {
    // Example input: User can change this
    vector<vector<int>> height = {
        {1, 4, 3, 1, 3, 2},
        {3, 2, 1, 3, 2, 4},
        {2, 3, 3, 2, 3, 1}
    };

    // Create solution object
    Solution sol;

    // Call the function and print the result
    int result = sol.trapRainWater(height);
    cout << "Total water trapped: " << result << endl;

    return 0;
}
