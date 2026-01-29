
// User function Template for C++

class Solution {
  public:
//   The pond has some leaves arranged in a straight line.
// Each frog has the strength to jump exactly K leaves. 
// For example, a  frog having strength 2 will visit the leaves 2, 4, 6, ...  etc. while crossing the pond.
    int unvisitedLeaves(int N, int leaves, int frogs[]) {
        vector<bool> visited(leaves + 1, false);
        for (int i = 0; i < N; i++) {
            int strength = frogs[i];
            // Skip if frog's strength is 0 or already processed
            if (strength == 0 || strength > leaves) continue;

            // If this frog's first leaf is already visited,
            // skip to avoid redundant marking
            if (visited[strength]) continue;

            for (int j = strength; j <= leaves; j += strength) {
                visited[j] = true;
            }
        }
        int count = 0;
        for (int i = 1; i <= leaves; i++) {
            if (!visited[i]) count++;
        }
        return count;
    }
};
