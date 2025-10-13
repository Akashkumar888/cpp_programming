
// 6. Rerooting / All-Nodes DP
// Compute DP for every node as root (re-rooting technique).
// ✅ Examples:
// Sum of distances from each node to all others (Leetcode 834)
// Count of nodes in each subtree & outside it
// Core idea:
// Use two DFS passes:
// First DFS → subtree information.
// Second DFS → use parent’s DP to update children’s results.