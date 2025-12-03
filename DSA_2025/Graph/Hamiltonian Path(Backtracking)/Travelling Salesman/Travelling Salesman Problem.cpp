
class Solution {
public:
    int n;
    vector<vector<int>> cost;
    vector<int> vis;
    int ans;

    void dfs(int node, int count, int currCost){
        if(count == n){
            ans = min(ans, currCost + cost[node][0]); // return to start
            return;
        }

        for(int nxt = 0; nxt < n; nxt++){
            if(!vis[nxt]){
                vis[nxt] = 1;
                dfs(nxt, count + 1, currCost + cost[node][nxt]);
                vis[nxt] = 0;
            }
        }
    }

    int tsp(vector<vector<int>>& costMatrix) {
        cost = costMatrix;
        n = cost.size();
        vis.assign(n, 0);

        ans = INT_MAX;
        vis[0] = 1;

        dfs(0, 1, 0);

        return ans;
    }
};
