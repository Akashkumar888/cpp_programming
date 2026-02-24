
#include <iostream>
#include <vector>
using namespace std;

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class DSU {
public:
    vector<int> parent;
    vector<int> size;
    vector<int> rank;

    // contructor in used for data members initiallization not declaration 
    DSU(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        rank.resize(n + 1, 0);

        for(int i = 1; i <= n; i++)parent[i] = i;
    }

    int find(int i) {
        if(i == parent[i]) return i;
        return parent[i] = find(parent[i]);
    }

    // union by size (we use this for counting pairs)
    long long unionsetBySize(int x, int y) {

        int x_parent = find(x);
        int y_parent = find(y);

        if(x_parent == y_parent) return 0;  // already connected

        // make bigger size as parent
        if(size[x_parent] < size[y_parent])
            swap(x_parent, y_parent);

        parent[y_parent] = x_parent;

        long long newPairs = 1LL * size[x_parent] * size[y_parent];

        size[x_parent] += size[y_parent];

        return newPairs;   // return newly formed valid paths
    }

    // union by rank (kept as you like structure complete)
    void unionsetByRank(int x, int y) {
        int x_parent = find(x);
        int y_parent = find(y);

        if(x_parent == y_parent) return;

        if(rank[x_parent] < rank[y_parent]) {
            parent[x_parent] = y_parent;
        }
        else if(rank[x_parent] > rank[y_parent]) {
            parent[y_parent] = x_parent;
        }
        else {
            parent[y_parent] = x_parent;
            rank[x_parent]++;
        }
    }
};

void maximum_weight_paths(int n,
                          vector<vector<int>> &edges,
                          int q,
                          vector<int> &queries,
                          vector<int> &result) {
    // lambda functions 
    auto cmp=[&](vector<int> &a, vector<int> &b) {
             return a[2] < b[2];
         };;

    // Step 1: sort edges by weight
    sort(edges.begin(), edges.end(),cmp);

    // Step 2: store queries with original index
    vector<pair<int,int>> qs;
    for(int i = 0; i < q; i++) {
        qs.push_back({queries[i], i});
    }

    sort(qs.begin(), qs.end());

    DSU dsu(n);

    long long currentPaths = 0;
    int edgeIndex = 0;

    // Step 3: process queries in increasing order
    for(auto &query : qs) {

        int X = query.first;
        int idx = query.second;

        // add all edges with weight <= X
        while(edgeIndex < n-1 && edges[edgeIndex][2] <= X) {

            int u = edges[edgeIndex][0];
            int v = edges[edgeIndex][1];

            currentPaths += dsu.unionsetBySize(u, v);

            edgeIndex++;
        }

        result[idx] = currentPaths;
    }
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> edges(n-1, vector<int>(3));
    for (int i = 0; i < n-1; i++) {
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }
    int q;
    cin >> q;
    vector<int> queries(q);
    for (int i = 0; i < q; i++) {
        cin >> queries[i];
    }
    vector<int> result(q);
    maximum_weight_paths(n, edges, q, queries, result);
    for (int i = 0; i < q; i++) {
        cout << result[i] << " ";
    }
    return 0;
}
