
class Solution {
public:
    int timer = 0;
    void dfs(int u, vector<int> adj[],vector<int>& tin, vector<int>& low,vector<bool>& inStack,stack<int>& st,vector<vector<int>>& scc){
        tin[u] = low[u] = timer++;
        
        st.push(u);
        inStack[u] = true;

        for (auto &v : adj[u]) {

            if (tin[v] == -1) {
                dfs(v, adj, tin, low, inStack, st, scc);
                low[u] = min(low[u], low[v]);
            }
            else if (inStack[v]) {
                low[u] = min(low[u], tin[v]);
            }
        }

        // 🔥 SCC FOUND
        if (low[u] == tin[u]) {
            vector<int> component;

            while (true) {
                int node = st.top();
                st.pop();
                inStack[node] = false;
                component.push_back(node);

                if (node == u) break;
            }

            sort(component.begin(), component.end()); // required
            scc.push_back(component);
        }
    }

    vector<vector<int>> tarjans(int V, vector<int> adj[]) {

        vector<int> tin(V, -1), low(V, -1);
        vector<bool> inStack(V, false);
        stack<int> st;
        vector<vector<int>> scc;

        for (int i = 0; i < V; i++) {
            if (tin[i] == -1) {
                dfs(i, adj, tin, low, inStack, st, scc);
            }
        }

        // 🔥 Sort all components lexicographically
        sort(scc.begin(), scc.end());

        return scc;
    }
};



// Critical Connections in a Network
class Solution {
public:
int timer=1;
void dfs(int u,int parent,vector<bool>&visited,vector<int>adj[],int tin[],int low[], vector<vector<int>>&bridge){
       visited[u]=true;
       tin[u]=low[u]=timer;
       timer++;
       for(auto &v:adj[u]){
        if(v==parent) continue;
        if(!visited[v]){
        dfs(v,u,visited,adj,tin,low,bridge);
        low[u]=min(low[u],low[v]);
        if(low[v] > tin[u])bridge.push_back({v,u});
        }
        else{
        low[u]=min(low[u],low[v]);
        }
       }
}
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>>bridge;
        vector<int>adj[n]; // adjancency list
        for(auto &it:connections){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool>visited(n,false);
        int tin[n];
        int low[n];
        dfs(0,-1,visited,adj,low,tin,bridge);
        return bridge;
    }
};