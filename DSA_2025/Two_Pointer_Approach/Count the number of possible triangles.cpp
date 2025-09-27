
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

class Solution {
  public:
    // Function to count the number of possible triangles.
    int countTriangles(vector<int>& arr) {
        // code here
        int n=arr.size();
        int count=0;
        sort(arr.begin(),arr.end(),greater<>());
        for(int i=0;i<n-2;i++){
            int l=i+1;
            int r=n-1;
            while(l<r){
                int sum=arr[l]+arr[r];
                if(arr[i]<sum){
                    count+=(r-l);
                    l++;
                }
                else r--;
            }
        }
        return count;
    }
};

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        // three side then i=2
        int cnt=0;
        for(int i=2;i<n;i++){
          int l=0;
          int r=i-1;
          while(l<r){
          if(nums[l]+nums[r]>nums[i]){
            cnt+=(r-l);
            r--;
          }
          else l++;
          }
        }
        return cnt;
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
