
// In a DAG, edges can only go forward in topological order.
// If topo order = t[0], t[1], ..., t[V-1]
// Then valid edge is only t[i] → t[j] where i < j.
// ✅ Maximum possible edges in a DAG
// For V nodes (in DAG), maximum acyclic edges possible:
// MaxEdges=V⋅(V−1)/2

// Why? → Because in topo order, every earlier node can connect to every later node.
// ✅ Our task
// Count how many edges are missing among these valid forward edges.
// So,
// Answer=MaxEdges−ExistingDirectedForwardEdges


// Build graph from edges
// Topologically sort the graph
// Create pos[] array, where pos[node] = index in topo order
// For each existing edge (u → v)
// If pos[u] < pos[v] → it is valid forward edge
// else (should never happen in DAG, but ignore)
// Count these edges → forward_edges
// Output:V(V−1)/2 ​ − forward_edges

class Solution {
  public:
    int maxEdgesToAdd(int V, vector<vector<int>>& edges) {
        // code here
    // topo+BFS is kahn's algorithm 
    // where each entry edges[i] = [u, v] denotes a directed edge from
    // vertex u to vertex v, find the maximum number of additional edges that can be added to the graph without forming any cycles
    // total number of edges V*(V-1)/2 
     unordered_map<int,vector<int>>adj;
     vector<int>indegree(V,0);
    //  int maxEdges=V*(V-1)/2;
     for(auto &edge:edges){
         int u=edge[0];
         int v=edge[1];
         adj[u].push_back(v);
         indegree[v]++;
     }
     // topo+BFS is kahn's algorithm 
    //Kahn’s algorithm (Topological Sort)
     queue<int>q;
     for(int i=0;i<V;i++){
         if(indegree[i]==0)q.push(i);
     }
     vector<int> topo;
     while(!q.empty()){
         int u=q.front();
         q.pop();
         topo.push_back(u);
         for(auto &v:adj[u]){
         indegree[v]--;
         if(indegree[v]==0){
             q.push(v);
         }
        }
     }
    // pos[node] = index in topo order
        vector<int> pos(V);
        for (int i = 0; i < V; i++)pos[topo[i]] = i;
        int forward_edges = 0;
        for (auto &e : edges) {
            int u = e[0], v = e[1];
            if (pos[u] < pos[v])
                forward_edges++;
        }
        long long maxPossible = 1LL * V * (V - 1) / 2;
        return maxPossible - forward_edges;
    }
};


class Solution {
  public:
    int maxEdgesToAdd(int V, vector<vector<int>>& edges) {
        // code here
    // topo+BFS is kahn's algorithm 
    // where each entry edges[i] = [u, v] denotes a directed edge from
    // vertex u to vertex v, find the maximum number of additional edges that can be added to the graph without forming any cycles
    // total number of edges V*(V-1)/2 
     unordered_map<int,vector<int>>adj;
     vector<vector<bool>>edgeExist(V,vector<bool>(V,false));
     vector<int>indegree(V,0);
    //  int maxEdges=V*(V-1)/2;
     for(auto &edge:edges){
         int u=edge[0];
         int v=edge[1];
         adj[u].push_back(v);
         indegree[v]++;
         edgeExist[u][v]=true;
     }
     // topo+BFS is kahn's algorithm 
    //Kahn’s algorithm (Topological Sort)
     queue<int>q;
     for(int i=0;i<V;i++){
         if(indegree[i]==0)q.push(i);
     }
     vector<int> topo;
     while(!q.empty()){
         int u=q.front();
         q.pop();
         topo.push_back(u);
         for(auto &v:adj[u]){
         indegree[v]--;
         if(indegree[v]==0){
             q.push(v);
         }
        }
     }
     int countEdge=0;
     for(int i=0;i<V;i++){
         for(int j=i+1;j<V;j++){
            int u=topo[i];
            int v=topo[j];
            if(!edgeExist[u][v])countEdge++;
         }
     }
    return countEdge;
    }
};

// ✅ Why no topo sort?
// Because:
// Problem guarantees graph is already DAG
// So no existing edge violates topo direction
// We only need to know how many edges are missing from the complete DAG

// They say Expected Time: O(1), Aux Space: O(1) because they expect you to realize this:
// In a DAG, the maximum possible edges is
// And since the graph is already guaranteed to be a DAG,
// every given edge is already valid (forward in some topo order).
// So the answer is simply:
// additional edges = V(V−1)/2​ − E
// We do not need to compute topological sort or adjacency list.

class Solution {
  public:
    int maxEdgesToAdd(int V, vector<vector<int>>& edges) {
        // code here
        // total number of edges V*(V-1)/2 
        long long maxPossible = 1LL * V * (V - 1) / 2;
        return maxPossible - edges.size();
    }
};
