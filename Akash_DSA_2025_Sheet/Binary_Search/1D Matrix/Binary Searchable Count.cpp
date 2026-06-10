
class Solution {
  public:
    bool binarySearch(vector<int>& arr, int target) {
        int l = 0;
        int r = arr.size() - 1;
        while(l <= r) {
            int mid = l + (r - l) / 2;
            if(arr[mid] == target)return true;
            else if(arr[mid] < target) {
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        return false;
    }
    int binarySearchable(vector<int>& arr) {
        int n = arr.size();
        int count = 0;
        for(int i = 0; i < n; i++) {
            if(binarySearch(arr, arr[i])) {
                count++;
            }
        }
        return count;
    }
};