
class Solution {
public:
// The diagonals in the bottom-left triangle (including the middle diagonal) are sorted in non-increasing order.
// The diagonals in the top-right triangle are sorted in non-decreasing order.
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        map<int,vector<int>>mp;
        int n=grid.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)mp[i-j].push_back(grid[i][j]);
        }
        for(auto &it:mp){
           if(it.first>=0) sort(it.second.begin(),it.second.end());
           else sort(it.second.begin(),it.second.end(),greater<>());
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                grid[i][j]=mp[i-j].back();
                mp[i-j].pop_back();
            }
        }
        return grid;
    }
};

class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        
        // store diagonals into heaps
        map<int, priority_queue<int>> maxHeap; // for decreasing order
        map<int, priority_queue<int, vector<int>, greater<int>>> minHeap; // for increasing order
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int key = i - j;
                if (key >= 0) {
                    maxHeap[key].push(grid[i][j]);   // bottom-left
                } else {
                    minHeap[key].push(grid[i][j]);   // top-right
                }
            }
        }

        // fill back the grid
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int key = i - j;
                if (key >= 0) {
                    grid[i][j] = maxHeap[key].top();
                    maxHeap[key].pop();
                } else {
                    grid[i][j] = minHeap[key].top();
                    minHeap[key].pop();
                }
            }
        }
        return grid;
    }
};

