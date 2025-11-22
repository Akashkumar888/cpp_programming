


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
             count+=(j-i+1); // subarray count it count no of distinct subarray upto j th index and also size of subarray
            j++;
        }
        return count;
}
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int exactly= atmost(nums,k) - atmost(nums,k-1);
        return exactly;
    }
};






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

int atleast(vector<int>& nums, int k) {
        int totalSubarrays =(nums.size()*(nums.size()+1))/2; 
        int lessThanK =atmost(nums,k-1);
        return totalSubarrays-lessThanK;
}

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        // int exactly= atmost(nums,k) - atmost(nums,k-1);
        // return exactly;
        int atleastK =atleast(nums,k);        
        int atleastKPlusOne =atleast(nums,k+1); 
        return atleastK-atleastKPlusOne;  
    }
};
