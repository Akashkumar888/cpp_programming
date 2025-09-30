
class Solution {
public:
    void f(int i, int n, vector<int>& nums, vector<int>& temp,
           set<vector<int>>& ans) {  // use set instead of vector
        if (i == n) {
            ans.insert(temp);
            return;
        }

        temp.push_back(nums[i]); 
        f(i + 1, n, nums, temp, ans);
        temp.pop_back();

        f(i + 1, n, nums, temp, ans); 
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // sort to keep order
        set<vector<int>> st;
        vector<int> temp;
        int n = nums.size();
        f(0, n, nums, temp, st);

        return vector<vector<int>>(st.begin(), st.end());
    }
};


class Solution {
public:
void f(int i,int n,vector<int>&nums,vector<int>&temp,vector<vector<int>>&ans){
          ans.push_back(temp);
          //Although there is no explicit base case (if (i >= n)), recursion terminates because the for loop runs only while j < n. When j exceeds n, the loop ends, and no further recursive calls are made. This naturally stops the recursion.
      for(int j=i;j<n;j++){
          if(j>i && nums[j]==nums[j-1])continue;
          temp.push_back(nums[j]);
          f(j+1,n,nums,temp,ans);
          temp.pop_back();
      }
  }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        vector<int>temp;
        int n=nums.size();
        f(0,n,nums,temp,ans);
        return ans;
    }
};

