
class Solution {
  public:
    int totalElements(vector<int> &arr) {
        // code here
        int n=arr.size();
        unordered_map<int,int>mp;
        int i=0,j=0;
        int maxLen=0;
        while(j<n){
            mp[arr[j]]++;
            while(mp.size()>2){
                mp[arr[i]]--;
                if(mp[arr[i]]==0)mp.erase(arr[i]);
                i++;
            }
            maxLen=max(maxLen,j-i+1);
            j++;
        }
        return maxLen;
    }
};