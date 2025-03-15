
class Solution {
  public:
      int minJumps(vector<int>& arr) {
          int n = arr.size();
          if (n == 1) return 0; // Already at the last index
  
          int maxStep = arr[0], endStep = arr[0], step = 1;
  
          for (int i = 1; i < n; i++) {
              if (i > maxStep) return -1; // Cannot move forward
              if (i == n - 1) return step; // Reached last index
              
              maxStep = max(maxStep, i + arr[i]); // Update farthest reach
              
              if (i == endStep) { // Use a jump
                  step++;
                  endStep = maxStep;
              }
          }
          return -1; // Not reachable
      }
  };
  