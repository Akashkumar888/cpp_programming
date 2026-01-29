
class Solution {
  public:
    vector<int> longestSubarray(vector<int>& arr, int x) {
        vector<int> ans;
        deque<int> dq1, dq2;
        int n = arr.size();
        int start = 0, end = 0;
        int i = 0, j = 0;

        while (j < n) {
            while (!dq1.empty() && arr[dq1.back()] > arr[j]) dq1.pop_back();
            while (!dq2.empty() && arr[dq2.back()] < arr[j]) dq2.pop_back();
            
            dq1.push_back(j);
            dq2.push_back(j);

            while (arr[dq2.front()] - arr[dq1.front()] > x) {
                if (i == dq2.front()) dq2.pop_front();
                if (i == dq1.front()) dq1.pop_front();
                i++;
            }

            if (j - i > end - start) {
                start = i;
                end = j;
            }
            j++;
        }

        for (int j = start; j <= end; j++) ans.push_back(arr[j]);  
        return ans;
    }
};
