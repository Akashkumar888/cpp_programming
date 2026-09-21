
class Solution {
  public:
    int minMoves(vector<int>& arr) {
        // code here
        int n = arr.size();

        // mp[value] = index of value
        vector<int> mp(n + 1);
        for(int i = 0; i < n; i++){
            mp[arr[i]] = i;
        }

        // Find longest consecutive sequence
        // where positions are increasing

        int count = 1;
        int maxLength = 1;
        for(int value = 2; value <= n; value++){
            // value-1 comes before value
            if(mp[value - 1] < mp[value]){
                count++;
            }
            else{
                count = 1;
            }
            maxLength = max(maxLength, count);
        }
        // Move all remaining elements
        return n - maxLength;
    }
};