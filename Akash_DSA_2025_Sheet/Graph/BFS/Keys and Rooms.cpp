class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<bool>visited(n,false);
        queue<int>q;
        q.push(0);
        visited[0]=true;
        while(!q.empty()){
            int u=q.front();
            q.pop();
            for(auto &ngbr:rooms[u]){
                if(!visited[ngbr]){
                    q.push(ngbr);
                    visited[ngbr]=true;
                }
            }
        }
        for(int i=0;i<n;i++){
            if(visited[i]==false)return false;
        }
        return true;
    }
};