
// User function template for C++
class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        // Code Here
        int n=arr.size();
        int l=0,r=n-1;
        while(l<r){
            int mid=l+(r-l)/2;
            if(arr[mid]>arr[r]){
                l=mid+1;
            }
            else{
                r=mid;
            }
            }
            return r;
    }
};

class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        // Code Here
        int n=arr.size();
        int l=0,r=n-1;
        while(l<r){// when target is not given
            int mid=l+(r-l)/2;
            if(arr[mid]<arr[r]){
                r=mid;
            }
            else l=mid+1;
        }
        return l;//The array is right-rotated k times. 
    }
};
