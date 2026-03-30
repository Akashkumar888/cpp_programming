

//Prims Algorithm

class Solution {
  public:
    int minCost(vector<vector<int>>& houses) {
        // code here
        int V=houses.size();
        typedef pair<int,int>P;
        priority_queue<P,vector<P>,greater<P>>pq;
        vector<bool>visited(V,false);
        int minCost=0;
        pq.push({0,0});
        while(!pq.empty()){
            int wt=pq.top().first;
            int u=pq.top().second;
            pq.pop();
            if(visited[u])continue;
            visited[u]=true;
            minCost+=wt;
            for(int v=0;v<V;v++){
                if(!visited[v]){
                    int dist=abs(houses[u][0]-houses[v][0]) + abs(houses[u][1]-houses[v][1]);
                    pq.push({dist,v});
                }
            }
        }
        return minCost;
    }
};