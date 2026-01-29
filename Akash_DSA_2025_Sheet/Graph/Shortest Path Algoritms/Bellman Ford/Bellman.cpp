
// ✅ Bellman–Ford is used for GRAPHS THAT MAY CONTAIN NEGATIVE EDGE WEIGHTS.
// ✔ It works even when edges have negative weights
// ✔ It detects negative cycles
// ❌ But it is NOT used only for negative cycles.
// ⭐ When do we use Bellman–Ford?
// ✔ 1. When the graph has negative weights
// Dijkstra cannot handle negative edges, but Bellman–Ford can.

// ✔ 2. When we want to detect negative cycles
// If Bellman–Ford updates distance after V−1 relaxations → negative cycle exists.

// ✔ 3. When number of vertices is small or graph is sparse
// Because Bellman–Ford is O(V * E).
// ⭐ When do we NOT use Bellman–Ford?
// ❌ 1. When the graph has NO negative weights
// → Dijkstra is much faster.
// ❌ 2. For all-pairs shortest paths
// → Use Floyd–Warshall or Johnson’s Algorithm.
// ❌ 3. When graph is huge (Bellman–Ford is slow)
// ⭐ Correct Summary:
// ✔ Bellman–Ford handles negative weights
// ✔ Bellman–Ford detects negative cycles
// ❌ Bellman–Ford is NOT used “only for negative cycle problems"
// It is mainly a shortest path algorithm.
// ⭐ Why Bellman–Ford is NOT useful for your transformation problem?
// Because:
// You have only positive weights
// You need all-pairs shortest paths
// Graph size = 26 letters → tiny
// Best algorithm = Floyd–Warshall (26×26 matrix)
