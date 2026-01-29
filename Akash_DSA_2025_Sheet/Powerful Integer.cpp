
class Solution {
  public:
    int powerfulInteger(vector<vector<int>>& intervals, int k) {
        map<int, int> mp;
        for (auto& it : intervals) {
            int start = it[0];
            int end = it[1];
            mp[start]++;
            mp[end + 1]--;
        }

        int active = 0;
        int res = -1;
        int prev = 0;

        for (auto it = mp.begin(); it != mp.end(); it++) {
            int point = it->first;
            if (active >= k) {
                res = point - 1;  // Last valid point before this change
            }
            active += it->second;
        }

        return res;
    }
};

// ✅ Final Time & Space Complexity:
// Time Complexity: O(n log n)
// For n insertions into the map (log n for each).
// One traversal over the map (up to 2n keys at most).

// Auxiliary Space: O(n)
// Because you're storing up to 2n keys (start and end+1 for each interval).

