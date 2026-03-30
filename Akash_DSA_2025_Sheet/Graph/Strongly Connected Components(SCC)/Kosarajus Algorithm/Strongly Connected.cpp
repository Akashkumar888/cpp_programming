
class Solution{
	public:
	void dfsfill(int u,vector<int>adj[],vector<bool>&visited,stack<int>&st){
	    visited[u]=true;
	    for(auto &ngbr:adj[u]){
	        if(!visited[ngbr]){
	            dfsfill(ngbr,adj,visited,st);
	        }
	    }
	    st.push(u);
	}
	
	//Function to find number of strongly connected components in the graph.
	void dfscall(int u,vector<int>adjRev[],vector<bool>&visited){
	    visited[u]=true;
	    for(auto &ngbr:adjRev[u]){
	        if(!visited[ngbr]){
	            dfscall(ngbr,adjRev,visited);
	        }
	    }
	}
    int kosaraju(int V, vector<int> adj[]){
        //code here
        stack<int>st;
        vector<bool>visited(V,false);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                dfsfill(i,adj,visited,st);
            }
        }
        // reverse the graph
        vector<int>adjRev[V];
        for(int u=0;u<V;u++){
            for(int &v:adj[u]){
                adjRev[v].push_back(u);
            }
        }
        fill(visited.begin(),visited.end(),false);
        int countScc=0;
        
        while(!st.empty()){
            int node=st.top();
            st.pop();
            
             if(!visited[node]){
                dfscall(node,adjRev,visited);
                countScc++;
            }
        }
        return countScc;
    }
};




class Solution {
public:

    void dfsfill(int u, vector<vector<int>>& adj, vector<bool>& visited, stack<int>& st) {
        visited[u] = true;

        for (auto &ngbr : adj[u]) {
            if (!visited[ngbr]) {
                dfsfill(ngbr, adj, visited, st);
            }
        }

        st.push(u);
    }

    void dfscall(int u, vector<vector<int>>& adjRev, vector<bool>& visited) {
        visited[u] = true;

        for (auto &ngbr : adjRev[u]) {
            if (!visited[ngbr]) {
                dfscall(ngbr, adjRev, visited);
            }
        }
    }

    int kosaraju(int V, vector<vector<int>>& adj) {

        stack<int> st;
        vector<bool> visited(V, false);

        // Step 1
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfsfill(i, adj, visited, st);
            }
        }

        // Step 2: Reverse graph
        vector<vector<int>> adjRev(V);

        for (int u = 0; u < V; u++) {
            for (auto v : adj[u]) {
                adjRev[v].push_back(u);
            }
        }

        // Step 3
        fill(visited.begin(), visited.end(), false);

        int countScc = 0;

        // Step 4
        while (!st.empty()) {
            int node = st.top();
            st.pop();

            if (!visited[node]) {
                dfscall(node, adjRev, visited);
                countScc++;
            }
        }

        return countScc;
    }
};
