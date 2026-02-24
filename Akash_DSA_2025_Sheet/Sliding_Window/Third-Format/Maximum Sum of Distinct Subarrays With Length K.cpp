
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
      int n=nums.size();
      long long maxSum=0;  
      long long sum=0;
      int j=0;
      unordered_map<int,int>mp;
      while(j<k){
        sum+=nums[j];
        mp[nums[j]]++;
        j++;
      }
      if(mp.size()==k)maxSum=max(maxSum,sum);
      int i=0;
      while(j<n){
        sum+=nums[j];
        mp[nums[j]]++;
        sum-=nums[i];
        mp[nums[i]]--;
        if(mp[nums[i]]==0)mp.erase(nums[i]);
        if(mp.size()==k){
        maxSum=max(maxSum,sum);
        }
        i++;
        j++;
      }
      return maxSum;
    }
};


class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
      int n=nums.size();
      long long maxSum=0;  
      long long sum=0;
      int j=0;
      unordered_map<int,int>mp;
      while(j<k){
        sum+=nums[j];
        mp[nums[j]]++;
        j++;
      }
      if(mp.size()==k)maxSum=max(maxSum,sum);
      int i=0;
      while(j<n){
        sum+=nums[j];
        mp[nums[j]]++;
        sum-=nums[i];
        
        if (mp[nums[i]] == 1)
            mp.erase(nums[i]);
        else
            mp[nums[i]]--;

        if(mp.size()==k){
        maxSum=max(maxSum,sum);
        }
        i++;
        j++;
      }
      return maxSum;
    }
};
