
class Solution {
  public:
    int maxWater(vector<int> &arr) {
        // code here
        int n=arr.size();
        int maxWater=0;
        int i=0,j=n-1;
        while(i<j){
            int mini=min(arr[i],arr[j]);
            int diff=j-i;
            maxWater=max(maxWater,diff*mini);
            if(arr[i]<arr[j])i++;
            else j--;
        }
        return maxWater;
    }
};

// Final Answer
// Time Complexity: O(n)
// Space Complexity: O(1)

