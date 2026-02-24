
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, pair<int,int>> P; 
// first = value (height or potency)
// second.first = row
// second.second = col

class DSU {
public:
    vector<int> parent;
    vector<int> size;
    vector<int> rank;

    DSU(int n) { // contructor in used for data members initiallization not declaration 
        parent.resize(n);
        size.resize(n, 1);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) parent[i] = i;
    }
    int find(int i) {
        if (i == parent[i]) return i;
        return parent[i] = find(parent[i]);
    }
    // -------- UNION BY SIZE --------
    void unionsetBySize(int x, int y) { // union ek keyword hai isliye unionset likho 
        int x_parent=find(x);
        int y_parent=find(y);
        if (x_parent == y_parent) return;

        if (size[x_parent] < size[y_parent]) {
            parent[x_parent] = y_parent;
            size[y_parent] += size[x_parent];
        } 
        else {
            parent[y_parent] = x_parent;
            size[x_parent] += size[y_parent];
        }
    }
    // -------- UNION BY RANK --------
    void unionsetByRank(int x, int y) {
        int x_parent = find(x);
        int y_parent = find(y);
        if (x_parent == y_parent) return;
        if (rank[x_parent] < rank[y_parent]) {
            parent[x_parent] = y_parent;// y ko x ka parent 
        }
        else if (rank[x_parent] > rank[y_parent]) {
            parent[y_parent] = x_parent;// x ko y ka parent
        }
        else {
            parent[y_parent] = x_parent; // x ko y ka parent
            rank[x_parent]++;   // jiska rank badao usko parent bana do dusre ka
        }
    }
};

void user_logic(int H, int W, vector<vector<int>>& grid, vector<pair<pair<int,int>, int>>&queries, vector<int>& result) {
    // Write your logic here.
    int total = H * W;
    DSU dsu(total);

    vector<P> cells;

    // Store cells as (height, (row, col))
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            cells.push_back({grid[i][j], {i, j}});
        }
    }

    sort(cells.begin(), cells.end());

    // Store queries as (potency, (row, col))
    vector<pair<P, int>> q; 
    // pair< P , original_index >

    for(int i = 0; i < queries.size(); i++) {
        int r = queries[i].first.first - 1;
        int c = queries[i].first.second - 1;
        int p = queries[i].second;

        q.push_back({{p, {r, c}}, i});
    }

    sort(q.begin(), q.end());

    vector<vector<bool>> active(H, vector<bool>(W, false));

    int ptr = 0;

    for(auto &query : q) {

        int p = query.first.first;
        int r = query.first.second.first;
        int c = query.first.second.second;
        int idx = query.second;

        // Activate cells with height < potency
        while(ptr < total && cells[ptr].first < p) {

            int x = cells[ptr].second.first;
            int y = cells[ptr].second.second;

            active[x][y] = true;

            int id = x * W + y;

            int dx[4] = {1, -1, 0, 0};
            int dy[4] = {0, 0, 1, -1};

            for(int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];

                if(nx >= 0 && ny >= 0 && nx < H && ny < W && active[nx][ny]) {
                    dsu.unionsetBySize(id, nx * W + ny);
                }
            }

            ptr++;
        }

        if(!active[r][c]) {
            result[idx] = 0;
        } else {
            int root = dsu.find(r * W + c);
            result[idx] = dsu.size[root];
        }
    }
}

int main() {
    int H, W, Q;
    cin >> H >> W >> Q;
    
    vector<vector<int>> grid(H, vector<int>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> grid[i][j];
        }
    }
    
    // pair< pair<r,c> , p >
    vector<pair<pair<int,int>, int>> queries(Q);

    for (int i = 0; i < Q; i++) {
        int r, c, p;
        cin >> r >> c >> p;

        queries[i] = {{r, c}, p};   // ✅ correct way
    }

    
    vector<int> result(Q);
    user_logic(H, W, grid, queries, result);
    
    for (int i = 0; i < Q; i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    
    return 0;
}
