

class Solution {
  public:
    int minJumps(vector<int>& arr) {
    int n = arr.size();
    if (n <= 1) return 0;            // already at the end
    if (arr[0] == 0) return -1;      // can't move anywhere

    int maxStep = arr[0];   // farthest we can go from index 0
    int endStep = arr[0];   // boundary of current jump
    int step = 1;           // at least one jump needed

    for (int i = 1; i < n; i++) {
        if (i > maxStep) return -1;  // can't reach index i
        if (i == n - 1) return step; // reached the last index

        maxStep = max(maxStep, i + arr[i]);

        if (i == endStep) {   // time to jump
            step++;
            endStep = maxStep;
        }
    }
    return -1;
    }
};





class Solution {
  public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if (n <= 1) return 0;            // already at the end
        if (arr[0] == 0) return -1;      // can't move anywhere

        int maxReach = arr[0];  // farthest index we can reach
        int steps = arr[0];     // steps we can still take in current jump
        int jumps = 1;          // we need at least one jump

        for (int i = 1; i < n; i++) {
            if (i == n - 1) return jumps;  // reached last index

            maxReach = max(maxReach, i + arr[i]);
            steps--;

            if (steps == 0) {
                jumps++;
                if (i >= maxReach) return -1;  // stuck, can't move further
                steps = maxReach - i;          // reset steps for new jump
            }
        }
        return -1;
    }
};


