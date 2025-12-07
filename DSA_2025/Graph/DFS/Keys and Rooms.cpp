
class Solution {
public:
void dfs(int u,vector<bool>&visited,vector<vector<int>>& rooms){
    if(visited[u])return;
     visited[u]=true;
     for(auto &ngbr:rooms[u]){
        if(!visited[ngbr])dfs(ngbr,visited,rooms);
    }
}
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<bool>visited(n,false);
        dfs(0,visited,rooms);
        for(int i=0;i<n;i++){
            if(visited[i]==false)return false;
        }
        return true;
    }
};