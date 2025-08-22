class Solution {
  public:
   // binary search on answer hai 
  bool isPossible(vector<int>&arr,int mid,int k){
      int count=1;
      int sum=0;
      for(int &num:arr){
          sum+=num;
          if(sum>mid){
              count++;
              sum=num;
          }
          if(count>k)return false;
      }
      return true;
  }
    int findPages(vector<int> &arr, int k) {
        // code here
        // Each student is assigned a contiguous sequence of books. that's why not sort array
        int n=arr.size();
        if(n<k)return -1;
        int l=*max_element(arr.begin(),arr.end());
        int r=accumulate(arr.begin(),arr.end(),0);
        int minPages=r;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(isPossible(arr,mid,k)){
            // minimize the maximum number of pages
                minPages=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        return minPages;
    }
};
