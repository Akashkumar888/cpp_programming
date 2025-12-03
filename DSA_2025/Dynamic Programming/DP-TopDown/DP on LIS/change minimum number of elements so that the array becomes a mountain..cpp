
// ✅ PROBLEM SUMMARY (From Screenshot)
// You are given an array of size N.
// You must change minimum number of elements so that the array becomes a mountain.
// Mountain Definition:
// The value at left end and right end must be equal.
// As you move toward the center from both ends, the values must strictly increase.
// There must be a single peak in the middle, and then strictly decrease.
// Equivalent Reformulation:
// You're basically asked to convert array into bitonic (mountain) sequence where:
// arr[0] = arr[n-1]
// strictly increasing from 0 → peak
// strictly decreasing from peak → n-1
// So we need to find the maximum length bitonic subsequence with the constraint:
// value of first = value of last
// Then answer = N – maxMountainLength

// ✅ Correct DP Approach
// For each index i, compute:
// 1️⃣ LIS ending at i
// Use your LIS code but compute dp1[] fully.
// 2️⃣ LDS starting at i
// Use your LDS code but compute dp2[] fully (reverse LDS).
// 3️⃣ Combine:
// For every valid peak i:
// mountainLen[i] = LIS[i] + LDS[i] - 1
// 4️⃣ Answer:
// minChanges = N - max(mountainLen[i])

class Solution {
public:

    int solve(vector<int>& arr) {

        int n = arr.size();
        vector<int> lis(n, 1), lds(n, 1);

        // --------------------------
        // 1. LIS ending at each index
        // --------------------------
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(arr[j] < arr[i]){
                    lis[i] = max(lis[i], lis[j] + 1);
                }
            }
        }

        // --------------------------
        // 2. LDS starting from each index
        // --------------------------
        for(int i = n - 1; i >= 0; i--){
            for(int j = n - 1; j > i; j--){
                if(arr[j] < arr[i]){
                    lds[i] = max(lds[i], lds[j] + 1);
                }
            }
        }

        // --------------------------
        // 3. Find maximum mountain length
        // --------------------------
        int maxMountain = 1;

        for(int i = 0; i < n; i++){
            if(lis[i] > 1 && lds[i] > 1){   // must be valid peak
                maxMountain = max(maxMountain, lis[i] + lds[i] - 1);
            }
        }

        return n - maxMountain;  // minimum changes
    }
};
