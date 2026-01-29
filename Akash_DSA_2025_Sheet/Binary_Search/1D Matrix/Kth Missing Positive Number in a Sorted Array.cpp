
class Solution {
  public:
//   Given a sorted array of distinct positive integers arr[], You need to find the kth positive number that is missing from the arr[].
// 🔹 Idea behind the formula
// In a perfect array with no missing numbers, the values should be:
// Index	Expected value
// 0	      1
// 1	      2
// 2	      3
// 3	      4
// i	      i + 1
// But your array has missing positive integers.
// So at index mid:
// Expected value = mid + 1 beacause it is 0-based indexing array element
// Actual value = arr[mid]
// Why mid + 1?
// In a perfect array with no missing numbers, the sequence would be:
// Index:  0  1  2  3  4 ...
// Value:  1  2  3  4  5 ...
// So at index mid, the value should be:
// expected = mid + 1;
// But the array has missing numbers, so the actual value is:
// actual = arr[mid];
// 🔹 Missing numbers till mid
// missing = arr[mid] - (mid + 1);
// Meaning:
// Number of positive integers missing before index mid
// The difference tells us how many numbers are missing before this index.
// 🔹 The Formula missing = arr[mid] - (mid + 1)
// 📌 Meaning:
// Number of missing positive integers before arr[mid]     
    int kthMissing(vector<int> &arr, int k) {
        // code here
        int n=arr.size();
        int l = 0, r = n - 1;
        while(l <= r) {
            int mid = l + (r - l) / 2;
            int missing = arr[mid] - (mid + 1);
            //Number of missing positive integers before arr[mid]  
            // how many missing numbers from start
            if(missing < k) {
                l = mid + 1;
            } 
            else {
                r = mid - 1;
            }
        }
        // l is the index where kth missing lies
        return l + k;
    }
};