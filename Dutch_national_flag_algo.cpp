
#include <bits/stdc++.h>
using namespace std;

void sort012(vector<int>& nums) {
    int n = nums.size();
    int i = 0, j = 0, k = n - 1;

    while (j <= k) {
        if (nums[j] == 0) {
            swap(nums[i], nums[j]);
            i++;
            j++;
        } else if (nums[j] == 1) {
            j++;
        } else { // nums[j] == 2
            swap(nums[j], nums[k]);
            k--;
        }
    }
}

int main() {
    vector<int> nums = {0, 2, 1, 2, 0, 1, 1, 0};
    sort012(nums);
    cout << "Sorted array: ";
    for (int num : nums) cout << num << " ";
    return 0;
}
