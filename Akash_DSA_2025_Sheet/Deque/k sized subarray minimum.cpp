
class Solution {
public:
    vector<int> minOfSubarrays(vector<int>& arr, int k) {
        // write code here
        // sliding window ko slide krna hai one by one 
        // deque pop_front for left index
        // deque push_back for right index
        int n=arr.size();
        vector<int>result(n-k+1);//window
        deque<int>dq;
        for(int i=0;i<n;i++){
            // Step 1 // Step 1: remove out-of-window indices
            while(!dq.empty() && i - dq.front() >= k )dq.pop_front();
            while(!dq.empty() && arr[i] < arr[dq.back()]) dq.pop_back(); // monotonic order me otherwise pop kr do 
            // Step 2 // Step 2: add current index if negative
            dq.push_back(i);
             // Step 3: Store answer when window is ready
            if (i - k + 1 >= 0) {
                result[i-k+1]=(arr[dq.front()]);
            }
        }
        return result;
    }
};
