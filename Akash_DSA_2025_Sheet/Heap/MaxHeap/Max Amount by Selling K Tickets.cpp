
class Solution {
  public:
  int mod=1e9+7;
    // 2 3 4 4 6 k = 3
    int maxAmount(vector<int>& arr, int k) {
        // code here
        int n=arr.size();
        priority_queue<int>pq(arr.begin(),arr.end());
        int maxAmount=0;
        while(!pq.empty() && k--){
            int maxValue=pq.top();
            pq.pop();
            maxAmount=(maxAmount+maxValue)%mod;
            if(maxValue-1>0)pq.push(maxValue-1);
        }
        return maxAmount;
    }
};