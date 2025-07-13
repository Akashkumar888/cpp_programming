
class Solution {
public:
    int nonLisMaxSum(vector<int>& arr) {
        int n = arr.size();
        int totalSum = accumulate(arr.begin(), arr.end(), 0);
        vector<int> dp(n);           // store sum of LIS ending at i
        vector<int> prevIdx(n, -1);
        vector<int> len(n, 1);       // length of LIS ending at i

        for (int i = 0; i < n; i++) dp[i] = arr[i];  // initialize with the element itself

        int lis = 1;
        int lastIdx = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (arr[j] < arr[i]) {
                    if (len[j] + 1 > len[i] || (len[j] + 1 == len[i] && dp[j] + arr[i] < dp[i])) {
                        dp[i] = dp[j] + arr[i];    // ✅ sum
                        len[i] = len[j] + 1;        // ✅ length
                        prevIdx[i] = j;
                    }
                }
            }
            if (len[i] > lis || (len[i] == lis && dp[i] < dp[lastIdx])) {
                lis = len[i];
                lastIdx = i;
            }
        }

        vector<int> ans;
        while (lastIdx != -1) {
            ans.push_back(arr[lastIdx]);
            lastIdx = prevIdx[lastIdx];
        }

        int sum = 0;
        for (int &num : ans) sum += num;

        return totalSum - sum;
    }
};






class Solution {
public:
    int nonLisMaxSum(vector<int>& arr) {
        int n = arr.size();
        int totalSum = accumulate(arr.begin(), arr.end(), 0);
        vector<int> dp(n);           // store sum of LIS ending at i
        vector<int> prevIdx(n, -1);
        vector<int> len(n, 1);       // length of LIS ending at i

        for (int i = 0; i < n; i++) dp[i] = arr[i];  // initialize with the element itself

        int lis = 1;
        int lastIdx = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (arr[j] < arr[i]) {
                    if (len[j] + 1 > len[i] || (len[j] + 1 == len[i] && dp[j] + arr[i] < dp[i])) {
                        dp[i] = dp[j] + arr[i];    // ✅ sum
                        len[i] = len[j] + 1;        // ✅ length
                        prevIdx[i] = j;
                    }
                }
            }
            if (len[i] > lis || (len[i] == lis && dp[i] < dp[lastIdx])) {
                lis = len[i];
                lastIdx = i;
            }
        }
        int sum = 0;
        while (lastIdx != -1) {
            sum+=(arr[lastIdx]);
            lastIdx = prevIdx[lastIdx];
        }
        return totalSum - sum;
    }
};








class Solution {
  public:
    int nonLisMaxSum(vector<int>& arr) {
        int n = arr.size();
        int totalSum = accumulate(arr.begin(), arr.end(), 0);
        vector<int> dp(n, 1);           // length of LIS ending at i
        vector<int> lisSumArr(n);       // sum of LIS ending at i
        for (int i = 0; i < n; i++) lisSumArr[i] = arr[i];  // initialize with current element

        int maxLisLength = 1;
        int maxLisSum = arr[0];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (arr[j] < arr[i]) {
                    // if longer LIS found or same length with smaller sum
                    if (dp[j] + 1 > dp[i] || 
                       (dp[j] + 1 == dp[i] && lisSumArr[j] + arr[i] < lisSumArr[i])) {
                        dp[i] = dp[j] + 1;
                        lisSumArr[i] = lisSumArr[j] + arr[i];
                    }
                }
            }
            // check if this is the new best LIS
            if (dp[i] > maxLisLength || 
               (dp[i] == maxLisLength && lisSumArr[i] < maxLisSum)) {
                maxLisLength = dp[i];
                maxLisSum = lisSumArr[i];
            }
        }

        return totalSum - maxLisSum;
    }
};



// 🔹 Time Complexity: O(n^2)
// You have a double loop:
// So the time complexity is O(n²) where n is the size of the array.
// All other steps (accumulate, backtracking) are at most O(n).

// 🔹 Space Complexity: O(n)
// You're using:
// dp[n] → to store LIS length or LIS sum
// prevIdx[n] or lisSumArr[n]
// len[n] in one version
// Possibly ans[n] or implicit stack trace to rebuild the LIS (still O(n))
// So space complexity is O(n).
// ✅ Final Answer:


