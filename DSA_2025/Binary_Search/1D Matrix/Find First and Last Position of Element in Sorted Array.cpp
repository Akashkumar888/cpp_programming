
class Solution {
public:
int lowerbound(vector<int> arr, int x){
      int l=0,r=arr.size()-1;
      int first=-1;
      while(l<=r){
          int mid=l+(r-l)/2;
          if(arr[mid]==x){
              first=mid;
              r=mid-1;
          }
          else if(arr[mid]<x)l=mid+1;
          else if(arr[mid]>x)r=mid-1;
      }
      return first;
  }
  int upperbound(vector<int> arr, int x){
      int l=0,r=arr.size()-1;
      int last=-1;
      while(l<=r){
          int mid=l+(r-l)/2;
          if(arr[mid]==x){
              last=mid;
              l=mid+1;
          }
          else if(arr[mid]<x)l=mid+1;
          else if(arr[mid]>x)r=mid-1;
      }
      return last;
  }
    vector<int> searchRange(vector<int>& nums, int target) {
        int first=lowerbound(nums,target);
        int last=upperbound(nums,target);
        return {first,last};
    }
};
