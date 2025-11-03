
class Solution {
public:
    bool dfs(int u, vector<bool> &visited, vector<bool> &inRec, unordered_map<int,vector<int>>& adj) {
        visited[u] = true;
        inRec[u] = true;
        for (auto &v : adj[u]) {
            if (!visited[v] && dfs(v, visited, inRec, adj)) {
                return true;
            } 
            else if (inRec[v]) { 
                return true; // cycle found
            }
        }
        inRec[u] = false;
        return false;
    }
    vector<int> safeNodes(int V, vector<vector<int>>& edges) {
// A vertex with no outgoing edges is called a terminal node.
// A vertex is considered safe if every path starting from it eventually reaches a terminal node.
// Return an array containing all the safe vertices of the graph in ascending order.
// Terminal node Node with no outgoing edges
//Safe node	Node that can only go to terminal nodes or other safe nodes, never into a cycle
// Safe nodes = nodes that cannot reach any cycle and eventually reach a terminal node.
        unordered_map<int, vector<int>> adj;
        for (auto &it : edges) {
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
        }
        set<int> cycleNodes;
        for (int i = 0; i < V; i++) {
            vector<bool> visited(V,false);
            vector<bool> inRec(V,false);
            if (dfs(i, visited, inRec, adj)) {
                cycleNodes.insert(i);
            }
        }
        vector<int> result;
        for (int i = 0; i < V; i++) {
            if (cycleNodes.find(i) == cycleNodes.end()) 
                result.push_back(i);
        }
        return result;
    }
};


// User function Template for C++

class Solution {
  public:
  bool dfscycle(vector<int>adj[],int u,vector<bool>&visited,vector<bool>&inrec,vector<bool>&check){
      visited[u]=true;
      inrec[u]=true;
      check[u]=false;
      for(int &v:adj[u]){
          if( !visited[v] && dfscycle(adj,v,visited,inrec,check)==true){
              
              // check[u]=false;
              return true;
          }
          else if(inrec[v]==true){
              //check[u]=false;
              return true;
          }
      }
      inrec[u]=false;
      check[u]=true;
      return false;
  }
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        vector<bool>visited(V,false);
        vector<bool>inrec(V,false);
        
        vector<bool>check(V,false);
        
        for(int i=0;i<V;i++){
            if(!visited[i]){
                dfscycle(adj,i,visited,inrec,check);
            }
        }
        
        vector<int>safe;
        
        for(int i=0;i<V;i++){
            if(check[i]==true) safe.push_back(i);
        }
        return safe;
        
    }
};

class Solution {
public:
    vector<int> safeNodes(int V, vector<vector<int>>& edges) {
// A vertex with no outgoing edges is called a terminal node.
// A vertex is considered safe if every path starting from it eventually reaches a terminal node.
// Return an array containing all the safe vertices of the graph in ascending order.
// Terminal node Node with no outgoing edges
//Safe node	Node that can only go to terminal nodes or other safe nodes, never into a cycle
// Safe nodes = nodes that cannot reach any cycle and eventually reach a terminal node.
        vector<vector<int>> adjRev(V);
        //         For competitive programming (like this problem)
        // ✅ vector<vector<int>> adj is best and fastest when:
        // Nodes are labeled 0 to V-1
        // You know V beforehand
        // Best performance & safest → Use this
        // O(1) access time (faster than unordered_map)
        // Memory is continuous (cache-friendly)
        // No hashing overhead

        // vector<int>adjRev[V];
        //Create an array of V vectors, where each element of the array is a vector<int>.
        // So:
        // adjRev = name of the array
        // [V] = array has V elements
        // each element is vector<int>

        // unordered_map<int,vector<int>>adjRev;
        vector<int> outDegree(V, 0);

        // Build reverse graph & outdegree count
        // Reverse Graph + Kahn’s Algorithm (Topological BFS)
        for (auto &e : edges) {
            int u = e[0], v = e[1];
            adjRev[v].push_back(u);
            outDegree[u]++;
        }
        queue<int> q;
        vector<int> safe;
        // terminal nodes = outdegree 0
        for (int i = 0; i < V; i++) {
            if (outDegree[i] == 0)
                q.push(i);
        }
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            safe.push_back(u);

            for (auto &v : adjRev[u]) {
                outDegree[v]--;
                if (outDegree[v] == 0)
                    q.push(v);
            }
        }
        sort(safe.begin(), safe.end());
        return safe;
    }
};