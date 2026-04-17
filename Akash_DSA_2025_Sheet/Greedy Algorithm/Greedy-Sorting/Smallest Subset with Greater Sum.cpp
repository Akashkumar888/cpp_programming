// User function Template for C++

class Solution {
  public:
    // Function to find the minimum number of elements in the first subset.
    int minSubset(vector<int> &arr) {
        // code here
        int n=arr.size();
        int totalSum=accumulate(arr.begin(),arr.end(),0);
        sort(arr.begin(),arr.end(),greater<>());
        int minCount=1;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            if(sum>(totalSum-sum)){
                return minCount;
            }
            else minCount++;
        }
        return 0;
    }
};
