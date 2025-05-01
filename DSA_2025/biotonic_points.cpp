


class Solution {
  public:
    int findMaximum(vector<int> &arr) {
        // code here
        int n=arr.size();
        int l=0,r=n-1;
        while(l<r){ // jb target na pta ho 
            int mid=l+(r-l)/2;
            if(arr[mid-1]<arr[mid] && arr[mid]>arr[mid+1])return arr[mid];
            else if(arr[mid-1]<arr[mid])l=mid+1;
            else r=mid;
        }
        return arr[n-1];
    }
  };


