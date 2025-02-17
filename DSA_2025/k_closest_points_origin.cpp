
class Solution {
  public:
      vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
          typedef pair<int, pair<int, int>> P;
          vector<vector<int>> ans;
          priority_queue<P> pq;
  
          for (auto &it : points) {
              int x = it[0];
              int y = it[1];
              int num = x * x + y * y;  // Squared distance (avoiding sqrt for efficiency)
              pq.push({num, {x, y}});
              if (pq.size() > k) pq.pop();
          }
  
          while (!pq.empty()) {
              ans.push_back({pq.top().second.first, pq.top().second.second});
              pq.pop();
          }
          return ans;
      }
  };
  