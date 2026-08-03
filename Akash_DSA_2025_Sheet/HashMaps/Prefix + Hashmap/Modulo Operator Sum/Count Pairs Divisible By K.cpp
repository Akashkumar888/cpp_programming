
class Solution {
  public:
    int countKdivPairs(vector<int>& arr, int k) {
        // code here
         int count=0;
         unordered_map<int,int>mp;
         for(int &num:arr){
             int mod = ((num % k) + k) % k; //Use ((x % k) + k) % k when negative numbers exist,
             int need=(k-mod)%k;
             if(mp.find(need)!=mp.end())count+=mp[need];
             mp[mod]++;
         }
         return count;
    }
};