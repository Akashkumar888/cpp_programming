

class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        // code here
        int n=arr.size();
        vector<int>ans;
        deque<int>dq;
        for(int i=0;i<n;i++){
           while(!dq.empty() && dq.front()<=i-k) dq.pop_front(); // window shrink karo
           while(!dq.empty() && arr[i]> arr[dq.back()]) dq.pop_back(); // monotonic order me otherwise pop kr do 
           dq.push_back(i);
           if(i>=k-1){
               ans.push_back(arr[dq.front()]);
           }
        }
        return ans;
    }
};
