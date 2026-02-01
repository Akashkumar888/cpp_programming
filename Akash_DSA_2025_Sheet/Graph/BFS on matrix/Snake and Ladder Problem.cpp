
// User function Template for C++

class Solution {
  public:
  //minimum number of dice throws required to reach the destination or last cell (30th cell) from the source (1st cell).
  // i think use bfs(queue)
    int minThrow(int N, int arr[]) {
        // code here
        typedef pair<int,int>P;
        // Step 1: create move array
        vector<int> move(31, -1);
        for (int i = 0; i < 2 * N; i += 2) {
            move[arr[i]] = arr[i + 1];
        }

        // Step 2: BFS
        vector<bool> visited(31, false);
        queue<P> q;

        // start from cell 1 with 0 throws
        q.push({1, 0});
        visited[1] = true;

        while (!q.empty()) {
            int cell=q.front().first;
            int dist=q.front().second;
            q.pop();

            // reached destination
            if (cell == 30)return dist;

            // try all dice throws
            for (int dice = 1; dice <= 6; dice++) {
                int next = cell + dice;
                if (next <= 30 && !visited[next]) {
                    visited[next] = true;

                    // if ladder or snake exists
                    if (move[next] != -1)next = move[next];

                    q.push({next, dist + 1});
                }
            }
        }
        return -1; // unreachable (should not happen)
    }
};