
#include <iostream>
#include <vector>
using namespace std;

class NumArray {
public:
    int n;
    vector<int> seg;

    void buildtree(int i, int l, int r, vector<int>& nums) {
        if (l == r) {
            seg[i] = nums[l];
            return;
        }
        int mid = l + (r - l) / 2;
        buildtree(2 * i + 1, l, mid, nums);
        buildtree(2 * i + 2, mid + 1, r, nums);
        seg[i] = seg[2 * i + 1] + seg[2 * i + 2];
    }

    void changeval(int i, int l, int r, int idx, int val) {
        if (l == r) {
            seg[i] = val;
            return;
        }
        int mid = l + (r - l) / 2;
        if (idx <= mid) changeval(2 * i + 1, l, mid, idx, val);
        else changeval(2 * i + 2, mid + 1, r, idx, val);
        seg[i] = seg[2 * i + 1] + seg[2 * i + 2];
    }

    int rangesum(int i, int l, int r, int st, int ed) {
        if (r < st || ed < l) return 0;
        if (st <= l && r <= ed) {
            return seg[i];
        }
        int mid = l + (r - l) / 2;
        return rangesum(2 * i + 1, l, mid, st, ed) + rangesum(2 * i + 2, mid + 1, r, st, ed);
    }

    NumArray(vector<int>& nums) {
        n = nums.size();
        seg.resize(4 * n);
        buildtree(0, 0, n - 1, nums);
    }

    void update(int index, int val) {
        changeval(0, 0, n - 1, index, val);
    }

    int sumRange(int left, int right) {
        return rangesum(0, 0, n - 1, left, right);
    }
};

int main() {
    // Test case
    vector<int> nums = {1, 3, 5}; // Initialize the array
    NumArray* obj = new NumArray(nums);

    // Testing sumRange
    cout << "Sum of range (0, 2): " << obj->sumRange(0, 2) << endl; // Output: 9

    // Update value at index 1 to 2
    obj->update(1, 2);

    // Testing sumRange again after update
    cout << "Sum of range (0, 2) after update: " << obj->sumRange(0, 2) << endl; // Output: 8

    // Clean up memory
    delete obj;

    return 0;
}
