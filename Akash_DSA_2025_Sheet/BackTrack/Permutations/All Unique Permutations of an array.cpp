
class Solution
{
public:
  void solve(int idx, vector<int> &arr, set<vector<int>> &result)
  {
    if (idx >= arr.size())
    {
      result.insert(arr);
      return;
    }
    for (int j = idx; j < arr.size(); j++)
    {
      swap(arr[idx], arr[j]);      // do
      solve(idx + 1, arr, result); // explore
      swap(arr[idx], arr[j]);      // undo
    }
  }
  vector<vector<int>> uniquePerms(vector<int> &arr)
  {
    // code here
    set<vector<int>> result;
    // distinct permutations of the array in sorted order.
    // A sequence A is greater than sequence B if there is an index i for which Aj = Bj for all j<i and Ai > Bi.
    solve(0, arr, result);
    vector<vector<int>> finalAns;
    for (auto &it : result)
    {
      finalAns.push_back(it);
    }
    return finalAns;
  }
};

class Solution {
public:
    void backtrack(vector<int>& arr, vector<int>& temp, vector<bool>& used, vector<vector<int>>& ans) {
        if(temp.size() == arr.size()) {
            ans.push_back(temp);
            return;
        }
        for(int i = 0; i < arr.size(); i++) {
            if(used[i]) continue;                  // already used in this permutation
            if(i > 0 && arr[i] == arr[i-1] && !used[i-1]) continue; // skip duplicates
            used[i] = true;
            temp.push_back(arr[i]);
            backtrack(arr, temp, used, ans);
            temp.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> uniquePerms(vector<int>& arr) {
        sort(arr.begin(), arr.end());  // sort to handle duplicates
        vector<vector<int>> ans;
        vector<int> temp;
        vector<bool> used(arr.size(), false);
        backtrack(arr, temp, used, ans);
        return ans;
    }
};


class Solution {
public:
void backtrack(int i,int n,vector<int>& nums,vector<vector<int>>&ans){
    if(i>=n){
        ans.push_back(nums);
        return;
    }
    unordered_set<int>seen;
    for(int j=i;j<n;j++){
        if(seen.find(nums[j])==seen.end()){
            seen.insert(nums[j]);
            swap(nums[i],nums[j]);
            backtrack(i+1,n,nums,ans);
            swap(nums[i],nums[j]);
        }
    }
}
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>ans;
        int n=nums.size();
        backtrack(0,n,nums,ans);
        return ans;
    }
};


class Solution
{
public:
  vector<vector<int>> uniquePerms(vector<int> &arr)
  {
    // code here
    // distinct permutations of the array in sorted order.
    // A sequence A is greater than sequence B if there is an index i for which Aj = Bj for all j<i and Ai > Bi.
    sort(arr.begin(), arr.end()); // sort array first
    vector<vector<int>> ans;
    do
    {
      ans.push_back(arr);
    } while (next_permutation(arr.begin(), arr.end()));
    return ans;
  }
};