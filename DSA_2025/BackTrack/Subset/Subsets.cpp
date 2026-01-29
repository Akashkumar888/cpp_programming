class Solution {
public:
void solve(int idx, int n, vector<int>& nums, vector<int>& temp, vector<vector<int>>& ans) {
    if (idx == n) {              // base case
        ans.push_back(temp);
        return;
    }

    ans.push_back(temp);  // still add current subset

    for (int j = idx; j < n; j++) {
        temp.push_back(nums[j]);
        solve(j+1, n, nums, temp, ans);
        temp.pop_back();
    }
}
    vector<vector<int>> subsets(vector<int>& nums) {
       vector<int>temp;
       vector<vector<int>>ans;
        int n=nums.size();
        solve(0,n,nums,temp,ans);
        return ans;
    }
};

class Solution {
public:
    void solve(int idx, int n, vector<int>& nums, vector<int>& temp, vector<vector<int>>& ans) {
        ans.push_back(temp);  // add current subset

        for (int j = idx; j < n; j++) {
            temp.push_back(nums[j]);   // choose nums[j]
            solve(j+1, n, nums, temp, ans); // explore further
            temp.pop_back();           // undo
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> ans;
        int n = nums.size();
        solve(0, n, nums, temp, ans);
        return ans;
    }
};


class Solution {
public:
void f(int i,int n,vector<int>&nums,vector<int>&temp,vector<vector<int>>&ans){
    if(i>=n){
        ans.push_back(temp);
        return;
    }
        temp.push_back(nums[i]); // do
        f(i+1,n,nums,temp,ans);// explore
        temp.pop_back(); // undo
        f(i+1,n,nums,temp,ans);// explore
}
    vector<vector<int>> subsets(vector<int>& nums) {
       vector<int>temp;
       vector<vector<int>>ans;
        int n=nums.size();
        f(0,n,nums,temp,ans);
        return ans;
    }
};


