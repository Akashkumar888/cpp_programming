
class Solution {
  public:
    int countMinOperations(vector<int>& arr) {
        int increments = 0;
        int maxDoublings = 0;
        for(int num : arr){
            // Count increment operations
            increments += __builtin_popcount(num);
            // Count how many times divisible by 2
            int doublings = 0;
            while(num > 1){
                num >>= 1;
                doublings++;
            }
            maxDoublings = max(maxDoublings, doublings);
        }
        return increments + maxDoublings;
    }
};
