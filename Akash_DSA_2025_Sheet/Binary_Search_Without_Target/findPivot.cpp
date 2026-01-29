// jb bhi l or r ko mid pe le ja ya jay to while loop me while(l<r) hi rahta hai
int findPivot(vector<int>& nums) {
    int l = 0, r = nums.size() - 1;
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (nums[mid] > nums[r]) {
            l = mid + 1;  // move right
        } else {
            r = mid;      // keep mid, move left
        }
    }
    return l;  // or r (both same here)
}

