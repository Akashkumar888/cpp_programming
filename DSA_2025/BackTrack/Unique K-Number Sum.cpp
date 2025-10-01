
class Solution
{
public:
  void solve(int idx, int sum, vector<int> &arr, int k, vector<vector<int>> &result, vector<int> &ans)
  {
    if (idx == arr.size())
    {
      if (sum == 0 && k == 0)
      {
        result.push_back(ans);
      }
      return;
    }
    if (idx >= arr.size() || sum < 0)
      return;
    //   int pick=0,notpick=0;
    //   if(arr[idx]<=sum){
    ans.push_back(arr[idx]);
    solve(idx + 1, sum - arr[idx], arr, k - 1, result, ans);
    //   }
    //   else{
    ans.pop_back();
    solve(idx + 1, sum, arr, k, result, ans);
    //   }
  }
  vector<vector<int>> combinationSum(int n, int k)
  {
    // code here
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    // Only numbers from the range [1, 9] used.
    // Each number can only be used at most once.
    vector<vector<int>> result;
    vector<int> ans;
    solve(0, n, arr, k, result, ans);
    return result;
  }
};

class Solution
{
public:
  void solve(int idx, int sum, vector<int> &arr, int k, vector<vector<int>> &result, vector<int> &ans)
  {
    if (idx == arr.size())
    {
      if (sum == 0 && k == 0)
      {
        result.push_back(ans);
      }
      return;
    }
    if (idx >= arr.size() || sum < 0)
      return;
    //   int pick=0,notpick=0;
    if (arr[idx] <= sum)
    {
      ans.push_back(arr[idx]);
      solve(idx + 1, sum - arr[idx], arr, k - 1, result, ans);
      ans.pop_back();
    }
    solve(idx + 1, sum, arr, k, result, ans);
  }
  vector<vector<int>> combinationSum(int n, int k)
  {
    // code here
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    // Only numbers from the range [1, 9] used.
    // Each number can only be used at most once.
    vector<vector<int>> result;
    vector<int> ans;
    solve(0, n, arr, k, result, ans);
    return result;
  }
};

class Solution
{
public:
  void solve(int idx, int sum, vector<int> &arr, int k, vector<vector<int>> &result, vector<int> &ans)
  {
    if (idx == arr.size())
    {
      if (sum == 0 && ans.size() == k)
      {
        result.push_back(ans);
      }
      return;
    }
    if (idx >= arr.size() || sum < 0)
      return;
    //   int pick=0,notpick=0;
    if (arr[idx] <= sum)
    { // only try pick if valid
      ans.push_back(arr[idx]);
      solve(idx + 1, sum - arr[idx], arr, k, result, ans);
      ans.pop_back();
    }
    // always try not-pick
    solve(idx + 1, sum, arr, k, result, ans);
  }
  vector<vector<int>> combinationSum(int n, int k)
  {
    // code here
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    // Only numbers from the range [1, 9] used.
    // Each number can only be used at most once.
    vector<vector<int>> result;
    vector<int> ans;
    solve(0, n, arr, k, result, ans);
    return result;
  }
};

class Solution
{
public:
  void solve(int sum, int nine, int k, vector<vector<int>> &result, vector<int> &ans)
  {
    if (sum == 0 && ans.size() == k)
    {
      result.push_back(ans);
      return;
    }
    if (nine == 0 || sum < 0)
      return;
    //   int pick=0,notpick=0;
    if (nine <= sum)
    {
      ans.push_back(nine);
      solve(sum - nine, nine - 1, k, result, ans); // arr me idx ki tarah move krna hai 9 to 1 tk
      ans.pop_back();
    }
    solve(sum, nine - 1, k, result, ans); // arr me idx ki tarah move krna hai 9 to 1 tk
  }
  vector<vector<int>> combinationSum(int n, int k)
  {
    // code here
    // vector<int>arr={1,2,3,4,5,6,7,8,9};
    // Only numbers from the range [1, 9] used.
    // Each number can only be used at most once.
    int nine = 9;
    vector<vector<int>> result;
    vector<int> ans;
    solve(n, nine, k, result, ans);
    return result;
  }
};

// Time Complexity:
// Same branching logic as Version 2/3.
// Still O(2^9) in worst-case, but cleanest pruning.
// Space Complexity:
// Same recursion depth ≤ 9 → O(1).
// No array → slightly less memory overhead.

// Version 4 is the best:
// Cleanest recursion (no arr array needed).
// Same time complexity as Version 2/3, but slightly less memory overhead.
// Easy to read and maintain.
