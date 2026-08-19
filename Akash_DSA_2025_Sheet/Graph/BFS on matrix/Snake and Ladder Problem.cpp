
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



class Solution {
public:
    int minThrows(int n, vector<int>& lad, vector<int>& sn) {

        int total = n * n;

        // move[i] = destination if snake/ladder starts at i
        vector<int> move(total + 1, -1);

        // Store ladders
        for (int i = 0; i < lad.size(); i += 2) {
            int start = lad[i];
            int end = lad[i + 1];

            move[start] = end;
        }

        // Store snakes
        for (int i = 0; i < sn.size(); i += 2) {
            int start = sn[i];
            int end = sn[i + 1];

            move[start] = end;
        }

        // BFS
        vector<bool> visited(total + 1, false);

        queue<pair<int, int>> q;

        // Start from cell 1 with 0 throws
        q.push({1, 0});
        visited[1] = true;

        while (!q.empty()) {

            int cell = q.front().first;
            int throws = q.front().second;
            q.pop();

            // Destination reached
            if (cell == total) {
                return throws;
            }

            // Try dice values 1 to 6
            for (int dice = 1; dice <= 6; dice++) {

                int next = cell + dice;

                if (next > total)
                    continue;

                // Take snake or ladder immediately
                if (move[next] != -1) {
                    next = move[next];
                }

                // Visit the final cell
                if (!visited[next]) {

                    visited[next] = true;

                    q.push({next, throws + 1});
                }
            }
        }

        return -1;
    }
};