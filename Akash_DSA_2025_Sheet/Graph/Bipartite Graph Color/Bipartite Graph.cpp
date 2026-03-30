
// A bipartite graph can be colored with two colors such that no two adjacent vertices share the same color. This means we can divide the graph’s vertices into two distinct sets where:

// All edges connect vertices from one set to vertices in the other set.
// No edges exist between vertices within the same set.

class Solution {
public:
bool DFS(vector<int>adj[],int curr,vector<int>&color,int currcolor){
    color[curr]=currcolor;
    for(int &v:adj[curr]){
        if(color[v]==color[curr])return false;
        if(color[v]==-1){
            color[v]=1-color[curr];
            if(DFS(adj,v,color,color[v])==false)return false;
        }
    }
    return true;
}
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    vector<int>color(V,-1);
	    for(int i=0;i<V;i++){
	        if(color[i]==-1){
	            if(DFS(adj,i,color,1)==false)return false;
	        }
	    }
	    return true;
	}

};



class Solution {
public:
bool BFS(vector<int>adj[],int curr,vector<int>&color,int currcolor){
    queue<int>q;
    q.push(curr);
    color[curr]=currcolor;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int &v:adj[u]){
            if(color[v]==color[u])return false;
            else if(color[v]==-1){
                color[v]=1-color[u];
                q.push(v);
            }
        }
    }
    return true;
}
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    vector<int>color(V,-1);
	    for(int i=0;i<V;i++){
	        if(color[i]==-1){
	            if(BFS(adj,i,color,1)==false)return false;
	        }
	    }
	    return true;
	}

};
