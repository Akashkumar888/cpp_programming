
// 4. Parent-Child Dependency DP
// State depends on whether parent has a certain property.
// ✅ Examples:
// Vertex Cover Problem in a Tree (choose minimum vertices so every edge is covered)
// Binary Tree Coloring Problem (Leetcode 1145)
// Minimum Cameras to Monitor All Nodes (Leetcode 968)
// Core idea:
// Multiple states per node: e.g. hasCamera, covered, needsCamera.