
class Solution {
  public:
    void rearrange(vector<int> &arr, int x) {
        // code here
        int n=arr.size();
        auto cmp=[&](int num1,int num2){
            return abs(x-num1)<abs(x-num2);
        };
        stable_sort(arr.begin(),arr.end(),cmp);
    }
};


// ⏱ Time Complexity
// stable_sort in C++ uses a merge sort variant under the hood.
// Complexity: O(n log n) comparisons.
// Each comparison calls abs(x - num), which is O(1).
// 👉 So total Time = O(n log n)

// 🗂 Space Complexity
// stable_sort is not in-place—it uses O(n) auxiliary space (unlike sort, which is O(log n)).
// 👉 So total Space = O(n)

