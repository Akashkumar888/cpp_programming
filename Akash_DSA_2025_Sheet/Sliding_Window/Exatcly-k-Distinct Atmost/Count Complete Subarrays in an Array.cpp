
class Solution {
public:
int atmost(vector<int>&nums,int k){
        int count=0;
        int i=0,j=0;
        int n=nums.size();
        unordered_map<int,int>mp;
        while(j<n){
            mp[nums[j]]++;
            while(mp.size()>k){
                mp[nums[i]]--;
                if(mp[nums[i]]==0)mp.erase(nums[i]);
                i++;
            }
             count+=(j-i+1);
            j++;
        }
        return count;
}
// The number of distinct elements in the subarray is equal to the number of distinct elements in the whole array.
// jb bhi exaclty vala sawal ho tb atmost condition lagana hi hai
    int countCompleteSubarrays(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mp1;
        for(auto &num:nums)mp1[num]++;
        int k=mp1.size();
        return atmost(nums,k)-atmost(nums,k-1);
    }
};


class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mp;
        for(int &num:nums){
            mp[num]++;//The number of distinct elements in the subarray is equal to the number of distinct elements in the whole array.
        }
        int k=mp.size();
        mp.clear();
        int i=0,j=0;
        int count=0;
        int odds=0;
        while(j<n){
            mp[nums[j]]++;
            while(mp.size()==k){
            count+=(n-j);
            mp[nums[i]]--;
            if(mp[nums[i]]==0)mp.erase(nums[i]);
            i++;
           }
           j++;
        }
        return count;
    }
};