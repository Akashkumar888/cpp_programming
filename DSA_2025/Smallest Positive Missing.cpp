
class Solution {
  public:
    int missingNumber(vector<int> &arr) {
        // code here
        int n=arr.size();// The array size is n
        int i=0;
        // Cyclic Sort: Place each element at its correct index
        while(i<n){
            int val=arr[i];
            // Only swap if the value is within [1, n) and not in the correct position
            if(val>=1 && val<n && arr[i]!=arr[val-1]){
                swap(arr[i],arr[val-1]);
            }
            else i++;
        }
        // After sorting, the first place where index+1 != value gives the missing number
        for(int i=0;i<n;i++){
            if(arr[i]!=i+1)return i+1;
        }
        // If all elements are in place, then the missing number is n+1
        return n+1;
    }
};

// ✅ Time Complexity:
// O(n) — Each element is swapped at most once, so the overall loop runs in linear time.

// ✅ Space Complexity:
// O(1) — In-place sorting is done; no extra space is used except for variables.

