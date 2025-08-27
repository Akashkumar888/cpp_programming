
class Solution {
  public:
    int countTriangles(vector<int>& arr) {
        // code here
        // if sum of any two sides is always greater than the third side.
        int n=arr.size();
        int count=0;
        sort(arr.begin(),arr.end());
        for(int i=2;i<n;i++){
            int l=0;
            int r=i-1;
            while(l<r){
                if(arr[l]+arr[r]>arr[i]){
                    count+=(r-l);
                    r--;
                }
                else {
                   l++;
                }
            }
        }
        return count;
    }
};

// Time Complexity
// Sorting:
// sort(arr.begin(), arr.end()); → O(n log n)
// Two-pointer loop:
// Outer loop (i from 2 to n-1): runs O(n) times.
// Inner loop (two-pointer scan for each i): in worst case, O(n) operations.
// So, this part → O(n^2)
// Total:
// O(n log n + n^2) = O(n^2)

// Space Complexity
// Sorting uses in-place quicksort/merge sort (introsort in C++) → O(log n) auxiliary stack space.
// Other than that, only constant variables → O(1).
