
int Solution::solve(int A, int B, int C, int D, vector<string> &E) {
    int n = E.size(), m = E[0].size();
    vector<vector<int>> dist(n, vector<int>(m, -1));
    queue<pair<int,int>> q;

    int sr = A-1, sc = B-1, tr = C-1, tc = D-1;
    q.push({sr, sc});
    dist[sr][sc] = 0;

    int dr[4] = {1, -1, 0, 0};
    int dc[4] = {0, 0, 1, -1};

    while(!q.empty()){
        auto [r, c] = q.front(); q.pop();

        for(int k = 0; k < 4; k++){
            int nr = r + dr[k], nc = c + dc[k];
            while(nr >= 0 && nr < n && nc >= 0 && nc < m && E[nr][nc] == '0'){
                if(dist[nr][nc] == -1){
                    dist[nr][nc] = dist[r][c] + 1;
                    q.push({nr, nc});
                }
                nr += dr[k];
                nc += dc[k];
            }
        }
    }

    return dist[tr][tc];
}
