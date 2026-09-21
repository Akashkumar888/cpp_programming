
class Solution {
public:
    int dominantPairs(vector<int> &arr) {
        int n = arr.size();
        int half = n / 2;
        
        // Sort each half separately
        sort(arr.begin(), arr.begin() + half, greater<int>());
        sort(arr.begin() + half, arr.end(), greater<int>());
        long long count = 0;
        int i = 0;
        int j = half;
        while (i < half && j < n) {
            if (arr[i] >= 5LL * arr[j]) {
                // Since second half is in decreasing order,
                // arr[j], arr[j+1], ... are all <= arr[j].
                // So all of them satisfy the condition.
                count += (n - j);

                i++;
            }
            else {
                j++;
            }
        }
        return count;
    }
};