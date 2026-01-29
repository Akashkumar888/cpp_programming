
class Solution {
  public:
//   containing elements from the range 1 to n, it is known that one number in this range is missing, and another number occurs twice in the array, find both the duplicate number and the missing number.
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
        int n=arr.size();
        int i=0;
        while(i<n){
            int val = arr[i];
            // if already 1 to n hai to thik otherwise only choose 1 to n number valid
            if (val >= 1 && val <= n && arr[i] != arr[val - 1]) {
    // Only place nums[i] if it lies within [1, n] and is not already in correct place
                swap(arr[i], arr[val - 1]);
            } 
            else {
                // Move ahead ONLY if:
                // 1) arr[i] already at correct position
                // 2) or arr[i] is the duplicate
                i++;
            }
        }
        
        int duplicate=-1,missing =-1;
        // After cyclic sort, find duplicate and missing
        for(int i=0;i<n;i++){
            if(arr[i]!=i+1){
                duplicate=arr[i];
                missing=i+1;
                break;
            }
        }
        return {duplicate,missing};
    }
};


class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
    int n = arr.size();
    
    long long naturalSum = (1LL * n * (n + 1)) / 2;
    long long naturalSquareSum = (1LL * n * (n + 1) * (2 * n + 1)) / 6;
    
    long long gridSum = 0, gridSquareSum = 0;
    for (int i = 0; i < n; i++) {
        gridSum += 1LL * arr[i];  // Convert to long long before summing
        gridSquareSum += 1LL * arr[i] * arr[i];  // Ensure long long multiplication
    }
    long long a = ((gridSquareSum - naturalSquareSum) / (gridSum - naturalSum) + (gridSum - naturalSum)) / 2;
    long long b = ((gridSquareSum - naturalSquareSum) / (gridSum - naturalSum) - (gridSum - naturalSum)) / 2;

    return {(int)a, (int)b};  // Convert back to int for output
    }
};

class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
        
        int n=arr.size();
        int repeating = -1, missing = -1;

    // Mark elements as visited by negating the value at the corresponding index
    for (int i = 0; i < n; i++) {
        int index = abs(arr[i]) - 1; // Map value to index (1-based to 0-based)
        if (arr[index] < 0) {
            // If already negative, this is the repeating element
            repeating = abs(arr[i]);
        } else {
            // Otherwise, mark it as visited
            arr[index] = -arr[index];
        }
    }

    // Find the missing number (index with positive value)
    for (int i = 0; i < n; i++) {
        if (arr[i] > 0) {
            missing = i + 1; // Missing number is the 1-based index
        }
    }

    return {repeating, missing};
    }
};