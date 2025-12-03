
// User function template for C++
class Solution {
  public:
  int upperBound(vector<int>& arr, int tr) {
    int l = 0, r = arr.size() - 1;
    int idx = arr.size(); // default: no element > tr
    while(l <= r){
        int mid = l + (r - l) / 2;
        if(arr[mid] > tr){
            idx = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    return idx;
}
// Sorted arr = [4, 5, 9, 10, 11, 12, 15, 100, 200]
    // Function to find the minimum number of elements to be removed.
    int minRemoval(vector<int>& arr) {
        // code here
        int n=arr.size();
        int minCount=INT_MAX;
        sort(arr.begin(),arr.end());
        for(int i=0;i<n;i++){
            int idx=upperBound(arr,arr[i]*2);
            minCount=min(minCount,i+(n-idx));
        }
        return minCount;
    }
};