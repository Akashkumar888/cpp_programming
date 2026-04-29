class Solution {
  public:
    bool canSplit(vector<int>& arr) {
        // code here
        int n=arr.size();
        int totalSum=accumulate(arr.begin(),arr.end(),0);
        int preSum=0;
        for(int i=0;i<n;i++){
            preSum+=arr[i];
            if(2*preSum==totalSum)return true;
        }
        return false;
    }
};
