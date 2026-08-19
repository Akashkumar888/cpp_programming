
class Solution {
public:
    // Count triplets having sum <= target
    long long countLessEqual(vector<int>& arr, int target) {
        int n = arr.size();
        long long count = 0;
        for (int i = 0; i < n - 2; i++) {
            int left = i + 1;
            int right = n - 1;
            while (left < right) {
                int sum = arr[i] + arr[left] + arr[right];
                // If current sum <= target,
                // then all elements from left to right-1
                // can form a valid triplet with arr[i]
                // and arr[right].
                if (sum <= target) {
                    count += (right - left);
                    left++;
                }
                else {
                    right--;
                }
            }
        }
        return count;
    }
    int countTriplets(vector<int> &arr, int l, int r) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        // Number of triplets with sum <= r
        long long rightCount = countLessEqual(arr, r);
        // Number of triplets with sum < l
        // Same as sum <= l-1
        long long leftCount = countLessEqual(arr, l - 1);
        return rightCount - leftCount;
    }
};