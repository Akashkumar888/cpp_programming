
class Solution {
  public:
//   int atmost(int nums[], int k, int n)
// int atmost(int *nums, int k, int n)
// Because in C++,
// int arr[] → decays to → int *arr
  int atmost(int nums[],int k,int n){
        int count=0;
        int i=0,j=0;
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
    int countDistinctSubarray(int arr[], int n) {
        // code here.
        unordered_map<int,int>mp1;
        for(int i=0;i<n;i++)mp1[arr[i]]++;
        int k=mp1.size();
        return atmost(arr,k,n)-atmost(arr,k-1,n);
    }
};
