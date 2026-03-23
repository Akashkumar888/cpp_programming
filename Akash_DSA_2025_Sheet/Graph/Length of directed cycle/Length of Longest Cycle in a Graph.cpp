
class Solution {
public:
    int longestCycle(int V, vector<vector<int>>& edges) {
        vector<int>adj(V,-1);
        //Each node has at most one outgoing edge.
       //That means not adjacency list, but a single next pointer
       //adj[u] = v   → u → v
        vector<int>indegree(V,0);
        for(auto &edge:edges){
            int u=edge[0];
            int v=edge[1];
            adj[u]=v;
            indegree[v]++;
        }
        queue<int>q;
        for(int i=0;i<V;i++){
            if(indegree[i]==0)q.push(i);
        }
        // remove non-cycle nodes (Kahn's)
        while(!q.empty()){
            int node=q.front(); 
            q.pop();

            int ngbr=adj[node];
            // Each node has at most ONE outgoing edge
            // So instead of:
            // node → multiple neighbors ❌
            // you have:
            // node → only ONE neighbor ✅
            if(ngbr!=-1){
                indegree[ngbr]--;
                if (indegree[ngbr]==0)q.push(ngbr);
            }
        }
        // count cycle length
        vector<bool>visited(V,false);
        int maxLen=-1;
        for(int i=0;i<V;i++){
            if(indegree[i] > 0 && !visited[i]){
                int count=0;
                int node=i;
                while(!visited[node]){
                    visited[node]=true;
                    node=adj[node];
                    count++;
                }
                maxLen=max(maxLen,count);
            }
        }
        return maxLen;
    }
};




class Solution {
public:
    int longestCycle(int V, vector<vector<int>>& edges) {
        vector<int> adj(V, -1);
        //Each node has at most one outgoing edge.
       //That means not adjacency list, but a single next pointer
       //adj[u] = v   → u → v
        for (auto &edge : edges){
            int u=edge[0];
            int v=edge[1];
            adj[u]=v;
        }
            
        vector<bool> visited(V, false);
        int maxLen = -1;

        for (int i = 0; i < V; i++) {
            if (visited[i]) continue;
            
            unordered_map<int,int> mp;
            int node = i;
            int step = 0;

            while (node != -1 && !visited[node]) {

                visited[node] = true;
                mp[node] = step++;
                node = adj[node];
                // Each node has at most ONE outgoing edge
            // So instead of:
            // node → multiple neighbors ❌
            // you have:
            // node → only ONE neighbor ✅
                if (node != -1 && mp.find(node)!=mp.end()) {
                    int cycleLen = step - mp[node];
                    maxLen = max(maxLen, cycleLen);
                    break;
                }
            }
        }
        return maxLen;
    }
};


// ⚡ Compare Both Cases
// Case 1 (Your Problem) ✅
// vector<int> adj(V);
// adj[2] = 5;
// Graph:
// 2 → 5
// Code:

// int ngbr = adj[node];
// Case 2 (General Graph) ✅
// vector<vector<int>> adj;
// adj[2] = {3,5,7};
// Graph:
// 2 → 3,5,7
// Code:
// for(auto ngbr : adj[node])
// 🔥 Why This Matters in Kahn’s
// In your code:
// int ngbr = adj[node];
// We are doing:

// remove edge: node → ngbr
// reduce indegree of ngbr
// Since only one outgoing edge exists, we don’t need loop.

// 🧠 Intuition Trick (Important)
// If problem says:
// Each node has at most one outgoing edge
// Immediately think:
// Use array (vector<int>) NOT adjacency list
// 🎯 Summary
// Graph Type	Representation	Traversal
// Single outgoing edge	vector<int>	direct access
// Multiple edges	vector<vector<int>>	for loop
// ⭐ Interview Insight
// 👉 This problem is special case graph (functional graph)
// That’s why:
// adj[node]
// instead of:
// for(auto ngbr : adj[node])


// ✅ Code (Multiple Outgoing Edges) BFS 
class Solution {
public:
    int longestCycle(int V, vector<vector<int>>& edges) {

        vector<vector<int>> adj(V);   // ✅ adjacency list
        vector<int> indegree(V, 0);

        // build graph
        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);   // multiple neighbors possible
            indegree[v]++;
        }

        queue<int> q;

        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        // remove non-cycle nodes (Kahn's)
        while (!q.empty()) {

            int node = q.front();
            q.pop();

            // 🔥 here we NEED loop
            for (auto ngbr : adj[node]) {

                indegree[ngbr]--;

                if (indegree[ngbr] == 0)
                    q.push(ngbr);
            }
        }

        // count remaining cycle nodes
        vector<bool> visited(V, false);
        int maxLen = -1;

        for (int i = 0; i < V; i++) {

            if (indegree[i] > 0 && !visited[i]) {

                int count = 0;
                queue<int> q2;

                q2.push(i);
                visited[i] = true;

                while (!q2.empty()) {
                    int node = q2.front(); q2.pop();
                    count++;

                    for (auto ngbr : adj[node]) {
                        if (indegree[ngbr] > 0 && !visited[ngbr]) {
                            visited[ngbr] = true;
                            q2.push(ngbr);
                        }
                    }
                }

                maxLen = max(maxLen, count);
            }
        }

        return maxLen;
    }
};



// MULTIPLE OUTGOING EDGES — DFS (Cycle Length)
class Solution {
public:

    int maxLen = -1;

    void dfs(int u,
             vector<vector<int>>& adj,
             vector<int>& visited,
             vector<int>& inRec,
             vector<int>& depth) {

        visited[u] = 1;
        inRec[u] = 1;

        for (auto &v : adj[u]) {

            if (!visited[v]) {
                depth[v] = depth[u] + 1;
                dfs(v, adj, visited, inRec, depth);
            }
            else if (inRec[v]) {
                // cycle found
                int cycleLen = depth[u] - depth[v] + 1;
                maxLen = max(maxLen, cycleLen);
            }
        }

        inRec[u] = 0;
    }

    int longestCycle(int V, vector<vector<int>>& edges) {

        vector<vector<int>> adj(V);

        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
        }

        vector<int> visited(V, 0), inRec(V, 0), depth(V, 0);

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfs(i, adj, visited, inRec, depth);
            }
        }

        return maxLen;
    }
};