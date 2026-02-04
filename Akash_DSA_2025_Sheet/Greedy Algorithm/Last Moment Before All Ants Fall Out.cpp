
class Solution {
  public:
// 0 ≤ left.length, right.length ≤ n + 1
// 0 ≤ left[i], right[i] ≤ n
// 1 ≤ left.length + right.length ≤ n + 1
  //All values of left and right are unique, and each value can appear only in one of the two arrays.
// Observations
// An ant moving left from position x will fall off the plank in x seconds. because it moves toward position 0. 
// An ant moving right from position x will fall off the plank in n - x seconds. because it moves toward position n.
// The last moment when all ants fall is simply the maximum time taken by any ant.


// Algorithm
// Initialize ans = 0
// For every ant in left[], update
// ans = max(ans, position)
// For every ant in right[], update
// ans = max(ans, n - position)
// Return ans

    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        // code here
        int maxTime = 0;

        // ants moving left
        for (int &pos : left) {
            maxTime = max(maxTime, pos);//because it moves toward position 0. 
        }

        // ants moving right
        for (int &pos : right) {
            maxTime = max(maxTime, n - pos);// because it moves toward position n.
        }
        //we take max of all because all ants fall out of the plank  
        return maxTime;
    }
};