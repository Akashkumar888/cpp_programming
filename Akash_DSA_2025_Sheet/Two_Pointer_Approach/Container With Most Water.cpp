
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

class Solution {
public:
    int maxArea(vector<int>& nums) {
        int n=nums.size();
        int maxArea=0;
        int i=0,j=n-1;
        while(i<=j){
            int height=min(nums[i],nums[j]);
            int width=j-i;
            int area=width*height;
            maxArea=max(area,maxArea);
            if(nums[i]<=nums[j])i++;
            else j--;
        }
        return maxArea;
    }
};