
class Solution {
  public:
    vector<vector<int>> levelSort(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> result;
        int idx = 0;
        int levelSize = 1;
        while(idx < n) {
            vector<int> level;
            for(int i = 0; i < levelSize && idx < n; i++) {
                level.push_back(arr[idx]);
                idx++;
            }
            sort(level.begin(), level.end());
            result.push_back(level);
            levelSize *= 2;
        }
        return result;
    }
};