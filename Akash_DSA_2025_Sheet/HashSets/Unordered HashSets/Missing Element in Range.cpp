
class Solution {
  public:
    vector<int> missinRange(vector<int>& arr, int low, int high) {
        // code here
        unordered_set<int>s(arr.begin(),arr.end());
        vector<int>result;
        for(int num=low;num<=high;num++){
            if(s.find(num)==s.end())result.push_back(num);
        }
        return result;
    }
};

// 1️⃣ Sorting + Pointer Approach
// Idea:
// Sort array
// Traverse from low to high
// Compare with array elements

vector<int> missingRange(vector<int>& arr, int low, int high) {
    sort(arr.begin(), arr.end());
    vector<int> result;

    int i = 0;
    int n = arr.size();

    for(int num = low; num <= high; num++) {
        while(i < n && arr[i] < num) i++;

        if(i >= n || arr[i] != num)
            result.push_back(num);
    }

    return result;
}

// ⏳ Complexity
// Sorting → O(n log n)
// Traversal → O(range)
// ⚠ Not optimal compared to hashing.
// 2️⃣ Boolean Array (Better When Range Small)
// If (high - low) is small:

vector<int> missingRange(vector<int>& arr, int low, int high) {
    vector<bool> present(high - low + 1, false);

    for(int num : arr) {
        if(num >= low && num <= high)
            present[num - low] = true;
    }

    vector<int> result;

    for(int i = 0; i < present.size(); i++) {
        if(!present[i])
            result.push_back(i + low);
    }

    return result;
}

// ✔ Time → O(n + range)
// ✔ Space → O(range)

// Sometimes better than unordered_set.
