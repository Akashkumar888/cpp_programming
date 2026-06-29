
class Solution {
  public:
    int maxArea(vector<int> &height) {
        // code here
        int n=height.size();
        int i=0,j=n-1;
        int maxArea=0;
        while(i<j){
            int length=min(height[i],height[j]);
            int width=j-i-1;
            int area=length*width;
            maxArea=max(maxArea,area);
            if(height[i]<height[j])i++;
            else j--;
        }
        return maxArea;
    }
};