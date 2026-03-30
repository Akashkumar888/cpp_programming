
class Solution {
  public:
    vector<int> minHeightRoot(int V, vector<vector<int>>& edges) {
        // Code here
        vector<int>degree(V,0);
        vector<int>adj[V];
        for(auto &edge:edges){
            int u=edge[0];
            int v=edge[1];
            adj[u].push_back(v);
            degree[v]++;
            adj[v].push_back(u);
            degree[u]++;
        }
        queue<int>q;
        for(int i=0;i<V;i++){
            if(degree[i]==1)q.push(i);
        }
        int remaining=V;
        while(remaining>2){
            int sz=q.size();
            remaining-=sz;
            while(sz--){
                int node=q.front();
                q.pop();
                for(auto &ngbr:adj[node]){
                    degree[ngbr]--;
                    if(degree[ngbr]==1)q.push(ngbr);
                }
            }
        }
        vector<int>result;
        while(!q.empty()){
            result.push_back(q.front());
            q.pop();
        }
        return result;
    }
};


// 🧠 1. Why degree instead of indegree?
// In directed graph (DAG):
// indegree → number of incoming edges
// In this problem:
// Graph is UNDIRECTED (tree)
// So:
// degree = total connections of a node
// 👉 Example:
// 2 connected to 0,1,3 → degree[2] = 3
// ❗ Important
// In undirected graph:
// indegree = outdegree = meaningless concept ❌
// degree = correct concept ✅
// 🧠 2. Why leaf = degree == 1 ?
// Because:
// Leaf node → only one connection
// Example:

// 0—2—3—4
//    |
//    1
// Leaves:
// 0,1,4 → degree = 1

// 🧠 3. Why remaining > 2 ?
// 👉 Key property of tree:
// Minimum height tree has at most 2 centers
// So:
// If 1 node → single center
// If even length path → 2 centers
// Example:
// 0—1—2—3
// Centers:
// 1,2 (2 nodes)
// 👉 So we stop when:
// remaining <= 2

// 🧠 4. What is remaining ?
// int remaining = V;
// 👉 It means:
// How many nodes are left after trimming leaves
// Each round:
// remaining -= number of leaves removed

// 🧠 5. Why BFS + Queue?
// We process layer by layer:
// Leaf layer 1 → remove
// Leaf layer 2 → remove
// ...
// Center remains
// 👉 This is exactly BFS behavior

// 🧠 6. Why this works (Main intuition)
// Think from opposite direction:
// Instead of finding root → we remove outer layers.

// Tree peeling like onion 🧅
// 🧠 7. Why NOT normal Kahn (DAG)?
// You are right:
// Kahn → usually for DAG ❗
// But here we use same idea (degree removal), not topological order.
// 👉 So:
// Concept reused, not problem type

// 🧠 8. Why queue size (sz)?
// int sz = q.size();
// 👉 This ensures:

// Remove ALL current leaves at once (one layer)
// 🔁 Flow Summary
// 1. Find all leaves (degree = 1)
// 2. Push into queue
// 3. Remove them
// 4. Reduce neighbors' degree
// 5. New leaves appear
// 6. Repeat
// 7. Stop when ≤ 2 nodes