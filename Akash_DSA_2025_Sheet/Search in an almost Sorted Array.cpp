

class Solution {
  public:
    int findTarget(vector<int>& arr, int target) {
        // code here
        int n=arr.size();
        int l=0,r=n-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(arr[mid]==target)return mid;
            if(arr[mid-1]==target)return mid-1;
            if(arr[mid+1]==target)return mid+1;
            else if(arr[mid]<target)l=mid+2;
            else if(arr[mid]>target)r=mid-2;
        }
        return -1;
    }
  };
  