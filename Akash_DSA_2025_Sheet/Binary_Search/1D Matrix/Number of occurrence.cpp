
class Solution {
  public:
  // lowerBound think start from first(0) when meet then r=mid-1;
  int firstOccurence(int n,vector<int>&arr,int tr){
      int l=0,r=n-1;
      int idx=-1;
      while(l<=r){
          int mid=l+(r-l)/2;
          if(arr[mid]<tr){
              l=mid+1;
          }
          else {
              idx=mid;
              r=mid-1;
          }
      }
      return idx;
  }
  // upperBound think start from last(n-1) when meet then l=mid+1
  int lastOccurence(int n,vector<int>&arr,int tr){
      int l=0,r=n-1;
      int idx=n;
      while(l<=r){
          int mid=l+(r-l)/2;
          if(arr[mid]>tr){
              r=mid-1;
          }
          else {
              idx=mid;
              l=mid+1;
          }
      }
      return idx;
  }
    int countFreq(vector<int>& arr, int target) {
        // code here
        int n=arr.size();
        int first=firstOccurence(n,arr,target);
        if(first==-1)return 0;
        int last=lastOccurence(n,arr,target);
        if(last==n)return 0;
        return last-first+1;// lenght like j-i+1
    }
};
