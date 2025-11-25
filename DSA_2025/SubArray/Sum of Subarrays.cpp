
class Solution {
  public:
    int subarraySum(vector<int>& arr) {
        // code here
        int n=arr.size();
        int totalSum=0;
        for(int i=0;i<n;i++){
            int left=(i+1);
            int right=(n-1-i+1);
            // odd or even element add how many subrray contain
            totalSum+=(left*right)*arr[i];
        }
        return totalSum;
    }
};
