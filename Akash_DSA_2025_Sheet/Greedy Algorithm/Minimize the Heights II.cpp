// Sort the array: arr[0] <= arr[1] <= ... <= arr[n-1]
// Consider splitting the array at index i:

// [0 .... i]        [i+1 .... n-1]
//   ↑                  ↑
//   increase +k        decrease -k


// Left part [0..i] → we increase by k
// Right part [i+1..n-1] → we decrease by k

// 🔹 Calculating minVal and maxVal

// New minimum height: could be
// smallest of left part after increase → arr[0] + k = smallest
// smallest of right part after decrease → arr[i+1] - k
// Hence:
// int minVal = min(smallest, arr[i+1] - k);


// New maximum height: could be
// largest of left part after increase → arr[i] + k
// largest of right part after decrease → arr[n-1] - k = largest
// Hence:
// int maxVal = max(largest, arr[i] + k);











class Solution {
  public:
    int getMinDiff(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        if (n == 1) return 0;

        sort(arr.begin(), arr.end());
        int ans = arr[n-1] - arr[0];

        int smallest = arr[0] + k;
        int largest = arr[n-1] - k;

        for (int i = 0; i < n - 1; i++) {
            int minVal = min(smallest, arr[i+1] - k);
            int maxVal = max(largest, arr[i] + k);

            if (minVal < 0) continue; // skip invalid (negative height)

            ans = min(ans, maxVal - minVal);
        }
        return ans;
    }
};

