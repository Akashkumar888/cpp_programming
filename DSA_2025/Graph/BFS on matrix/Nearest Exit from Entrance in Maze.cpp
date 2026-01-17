
class Solution {
public:
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size();
        int n = maze[0].size();
        queue<pair<int,int>> q;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        q.push({entrance[0], entrance[1]});
        visited[entrance[0]][entrance[1]] = true;
        int step = 0;
        while (!q.empty()) {
            int size = q.size();  // 🔥 BFS LEVEL SIZE
            while (size--) {
                auto [i, j] = q.front();
                q.pop();
                // exit check
                if ((i == 0 || j == 0 || i == m - 1 || j == n - 1) &&
                    !(i == entrance[0] && j == entrance[1])) {
                    return step;
                }
                for (int k = 0; k < 4; k++) {
                    int new_i = i + dx[k];
                    int new_j = j + dy[k];

                    if (new_i >= 0 && new_i < m &&
                        new_j >= 0 && new_j < n &&
                        maze[new_i][new_j] == '.' &&   // 🔥 wall check
                        !visited[new_i][new_j]) {

                        visited[new_i][new_j] = true;
                        q.push({new_i, new_j});
                    }
                }
            }
            step++;  // 🔥 increment AFTER one level
        }
        return -1;
    }
};



class Solution {
public:
vector<vector<int>>directions={{1,0},{0,1},{0,-1},{-1,0}};
typedef pair<int,pair<int,int>>P;
int bfs(int r,int c,int m,int n,vector<vector<char>>& maze){
    priority_queue<P,vector<P>,greater<P>>pq;
    vector<vector<bool>>visited(m,vector<bool>(n,false));
    pq.push({0,{r,c}});
    visited[r][c]=true;
    while(!pq.empty()){
        int cost=pq.top().first;
        int i=pq.top().second.first;
        int j=pq.top().second.second;
        pq.pop();
// ✅ Check for valid exit (not entrance and on boundary)
 // !(i == r && j == c)This ensures that the cell is not the entrance. Because the entrance could also be on the boundary, we don't want to treat the starting point as an exit.
        if((i == 0 || j == 0 || i == m-1 || j == n-1) && !(i == r && j == c)) {
           return cost;
        }
        for(auto &dir:directions){
            int x=i+dir[0];
            int y=j+dir[1];
            if(x>=0 && x<m &&y>=0&&y<n&&!visited[x][y]&&maze[x][y]=='.'){
                pq.push({cost+1,{x,y}});
                visited[x][y]=true;
            }
        }
    }
    return -1;
}
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m=maze.size();
        int n=maze[0].size();
        int r=entrance[0];
        int c=entrance[1];
        return bfs(r,c,m,n,maze);
    }
};


// ✅ BEST CODE: the FIRST one (Simple BFS with queue)
// Your first solution is the correct and best choice for this problem.
// The second solution (priority_queue / Dijkstra) is overkill and not optimal here.
// Why the FIRST code is best ✅
// 🔹 Problem nature
// Every move has equal cost = 1
// We need the minimum number of steps
// Graph is unweighted
// 👉 This is a textbook BFS problem
// 🔹 What BFS guarantees
// BFS explores level by level
// First time you reach an exit = shortest path
// Time complexity: O(m × n)
// Space complexity: O(m × n)
// Your first code:
// queue<pair<int,int>> q;
// int step = 0;
// while (!q.empty()) {
//     int size = q.size();   // one level
//     while (size--) {
//         ...
//         if (exit) return step;
//     }
//     step++;
// }

// ✔ Correct
// ✔ Clean
// ✔ Optimal
// ✔ Interview-preferred
// Why the SECOND code is NOT best ❌
// Your second solution uses:
// priority_queue<P, vector<P>, greater<P>> pq;
// This is Dijkstra’s algorithm.

// Correct Algorithm Choice (Interview Rule)
// Problem Type	Best Algorithm
// Unweighted shortest path	✅ BFS
// Weighted shortest path	Dijkstra
// Negative weights	Bellman-Ford
// All-pairs shortest path	Floyd-Warshall

// Final Verdict 🏆
// 🥇 Best Solution
// 👉 FIRST CODE (Queue + BFS level order)
// 🥈 Acceptable but NOT recommended
// 👉 Second code (priority_queue)