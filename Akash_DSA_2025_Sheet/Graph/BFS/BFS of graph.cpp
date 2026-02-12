
class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        // code here
        int V=adj.size();//Given a connected undirected graph containing V vertices
        vector<int>result;
        queue<int>q;
        vector<int>visited(V,false);
        q.push(0);//Perform a Breadth First Search (BFS) traversal starting from vertex 0
        visited[0]=true;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            result.push_back(node);
            for(auto &ngbr:adj[node]){
                if(!visited[ngbr]){
                    q.push(ngbr);
                    visited[ngbr]=true;
                }
            }
        }
        return result;
    }
};
