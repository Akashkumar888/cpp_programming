class Solution {
  public:
    int maxChildren(vector<int> &greed, vector<int> &cookie) {
        int m = greed.size();
        int n = cookie.size();
        sort(greed.begin(), greed.end());
        sort(cookie.begin(), cookie.end());
        int i = 0, j = 0;
        int count = 0;
        while (i < m && j < n) {
            if (cookie[j] >= greed[i]) {
                count++;   // child satisfied
                i++;       // move to next child
                j++;       // use next cookie
            } else {
                j++;       // cookie too small → try bigger cookie
            }
        }
        return count;
    }
};
