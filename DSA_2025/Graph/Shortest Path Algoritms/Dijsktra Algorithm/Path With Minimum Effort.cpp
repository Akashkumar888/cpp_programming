

class Solution {
  public:
//   Your task is to find the minimum possible path cost from the top-left cell (0, 0) to the bottom-right cell (n-1, m-1) by moving up, down, left, or right between adjacent cells.
//   The cost of a path is defined as the maximum absolute difference between the values of any two consecutive cells along that path.
  int dx[4]={-1,1,0,0};
  int dy[4]={0,0,-1,1};
    int minCostPath(vector<vector<int>>& mat) {
        // code here
        int n=mat.size();
        int m=mat[0].size();
        typedef pair<int,pair<int,int>>P;
        priority_queue<P,vector<P>,greater<P>>pq;
        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
        dist[0][0]=0;// starting point means source
        pq.push({0,{0,0}});// starting point means source
        int maxEffort=0;
        while(!pq.empty()){
            int cost=pq.top().first;
            int i=pq.top().second.first;
            int j=pq.top().second.second;
            pq.pop();
            if(i==n-1 && j==m-1)return cost;
            for(int k=0;k<4;k++){
                int ni=i+dx[k];
                int nj=j+dy[k];
                if(ni>=0&&ni<n&&nj>=0&&nj<m){
                    // int adjNode=mat[ni][nj];
                    // int wt=mat[ni][nj];
                    int diff = abs(mat[i][j] - mat[ni][nj]);
                    int newCost = max(cost, diff);
                    if(newCost<dist[ni][nj]){
                        dist[ni][nj]=newCost;
                        pq.push({newCost,{ni,nj}});
                    }
                }
            }
        }
        return 0;
    }
};



// ⭐ How to Identify 2D Dijkstra Algorithm Problems
// You know it is Dijkstra on a grid when:
// ✅ 1. The grid has weighted movement
// Here, weight = abs(mat[i][j] - mat[ni][nj])
// So every move has a cost → Dijkstra required.
// ✅ 2. You want to minimize a certain value
// Not BFS because BFS only works with equal cost edges.
// Here the cost is not equal, so BFS fails.
// ✅ 3. You have 4-direction (or 8-direction) movement
// This matches typical grid problems solved using Dijkstra.
// ✅ 4. The cost is not a sum, but something like max / min / product
// This problem uses:
// newCost = max(previous_cost, diff)