
class Solution {
public:
    // cycleDetection + Topo DFS
    // when dfs then topological sort
    bool dfs(int u, vector<bool> &inRec, vector<bool> &visited,unordered_map<int,vector<int>> &adj, vector<int> &result) {
        visited[u] = true;
        inRec[u] = true;
        
        for(auto &v : adj[u]) {
            if(!visited[v] && dfs(v, inRec, visited, adj, result))
                return true; // cycle detected
            else if(inRec[v])
                return true; // cycle detected
        }
        
        inRec[u] = false;
        result.push_back(u);  // ✅ push AFTER recursion (post-order)
        return false;
    }

    vector<int> findOrder(int n, vector<vector<int>> &prerequisites) {
        unordered_map<int, vector<int>> adj;
//  0 to n - 1 and a 2d array prerequisites[][] where prerequisites[i] = [x, y] indicates that we need to take course  y first if we want to take course x.
// Find the ordering of courses we should take to complete all the courses.
        for(auto &edge : prerequisites) {
            int u = edge[0];
            int v = edge[1];
            adj[v].push_back(u);
        }
        
        vector<bool> visited(n, false), inRec(n, false);
        vector<int> result;

        for(int i = 0; i < n; i++) {
            if(!visited[i] && dfs(i, inRec, visited, adj, result))
                return {};  // cycle exists → return empty order
        }
        reverse(result.begin(), result.end()); // ✅ reverse for topological order
        return result;
    }
};




class Solution {
public:
// kahn's algorithm 
// when bfs then topological -> kahn's algorithm 
     void topoBFS(int n,vector<int>&indegree,unordered_map<int,vector<int>>&graph,vector<int>&ans){
        queue<int>q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0)q.push(i);
        }  
        while(!q.empty()){
            int u=q.front();
            q.pop();
            ans.push_back(u);
            for(int &v:graph[u]){
                indegree[v]--;
                if(indegree[v]==0){
                    q.push(v);
                }
            }
        }
 }
    vector<int> findOrder(int n, vector<vector<int>> &prerequisites) {
        unordered_map<int,vector<int>>adj;
        vector<int>indegree(n,0);
    // prerequisites[][] where prerequisites[i] = [x, y] indicates that we need to take course  y first if we want to take course x.
    // Find the ordering of courses we should take to complete all the courses.
        for(auto &edge:prerequisites){
            int u=edge[0];
            int v=edge[1];
            adj[v].push_back(u);
            indegree[u]++;
        }
        vector<int>ans;
        topoBFS(n,indegree,adj,ans);
        if(ans.size()!=n) return {};
        return ans;
    }
};