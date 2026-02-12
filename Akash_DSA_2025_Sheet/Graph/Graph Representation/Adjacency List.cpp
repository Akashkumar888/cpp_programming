
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int,int>> adj[n+1];

    for(int i = 0; i < m; i++) {
        int u, v, wt;
        cin >> u >> v >> wt;

        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});   // undirected
    }

    return 0;
}



// ✅ Directed Graph (Adjacency List)
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int,int>> adj[n+1];

    for(int i = 0; i < m; i++) {
        int u, v, wt;
        cin >> u >> v >> wt;

        adj[u].push_back({v, wt});   // directed
    }

    return 0;
}

// adj is an array of vectors
// Each adj[u] stores a list of (v, weight) pairs
// 👉 Used in weighted graphs

// 🔹 Structure
// adj[u] = { {v1, wt1}, {v2, wt2}, {v3, wt3} }
// 🔹 Example
// adj[1].push_back({2, 5});
// adj[1].push_back({3, 10});

// 3️⃣ Adjacency List ⭐ (MOST USED)
// 🔹 Structure
// adj[u].push_back({v, wt});
// 🔹 Memory Efficient
// Only stores existing edges


// ✅ In Coding Interviews & CP:
// Always use adjacency list (vector)

// 6️⃣ Common Interview Questions
// Q1️⃣ Why adjacency list is preferred?
// ✔ Less memory
// ✔ Faster traversal
// ✔ Works with all algorithms
