
class Solution {
  public:
    long long solve(vector<int>& arr, long long limit){
        if(limit < 0) return 0;
        int n = arr.size();
        long long sum = 0;
        long long count = 0;
        int i = 0,j=0;
        while(j < n){
            sum += arr[j];
            while(sum > limit){
                sum -= arr[i];
                i++;
            }
            count += (j - i + 1);
            j++;
        }
        return count;
    }
    int countSubarray(vector<int>& arr, int l, int r) {
        return solve(arr, r) - solve(arr, l - 1);
    }
};

// Why does this trick work?
// Think of all subarrays as a set:

// All subarrays
// │
// ├── Sum ≤ l-1        ❌ Don't want
// └── Sum ≥ l

// Among those with Sum ≥ l, some have sums greater than r, so if we instead count all with Sum ≤ r, we get exactly the desired range by subtraction:

// Sum ≤ r
//     -
// Sum ≤ l-1
// =
// l ≤ Sum ≤ r

// This is why the solution is:
// return solve(arr, r) - solve(arr, l - 1);