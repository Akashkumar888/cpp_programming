
class Solution {
  public:
    vector<int> longestSubarray(vector<int>& arr, int x) {
        // code here
        int n = arr.size();
        int i = 0, j = 0;
        int start = 0, end = -1;
        int maxlen = 0;

        // maxHeap stores {value, index}
        priority_queue<pair<int,int>> maxHeap;
        // minHeap stores {value, index}
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;

        while (j < n) {
            maxHeap.push({arr[j], j});
            minHeap.push({arr[j], j});

            // shrink window if invalid
            while (!maxHeap.empty() && !minHeap.empty() &&
                   maxHeap.top().first - minHeap.top().first > x) {
                i++;
                // remove elements outside window (lazy deletion)
                while (!maxHeap.empty() && maxHeap.top().second < i) maxHeap.pop();
                while (!minHeap.empty() && minHeap.top().second < i) minHeap.pop();
            }

            // update answer
            if (j - i + 1 > maxlen) {
                maxlen = j - i + 1;
                start = i;
                end = j;
            }
            j++;
        }

        vector<int> ans;
        for (int k = start; k <= end; k++) ans.push_back(arr[k]);
        return ans;
    }
};