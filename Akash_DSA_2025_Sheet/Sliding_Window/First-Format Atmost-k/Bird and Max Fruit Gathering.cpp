
class Solution {
  public:
    int maxFruits(vector<int>& arr, int m) {
        // code here
        for(int i=0;i<m;i++)arr.push_back(arr[i]);
        int n=arr.size();
        int i=0,j=0;
        int sum=0;
        int maxSum=0;
        while(j<n){
            sum+=arr[j];
            if(j-i+1>m){
                sum-=arr[i];
                i++;
            }
            maxSum=max(maxSum,sum);
            j++;
        }
        return maxSum;
    }
};