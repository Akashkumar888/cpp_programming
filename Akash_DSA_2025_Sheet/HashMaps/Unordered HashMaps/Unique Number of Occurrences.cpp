
// User function Template for C++
class Solution {
  public:
    bool isFrequencyUnique(int n, int arr[]) {
        unordered_map<int,int>mp1,mp2;
        for(int i=0;i<n;i++){
           mp1[arr[i]]++;
        }
        for(auto &it:mp1){
            if(mp2.find(it.second)!=mp2.end())return false;
            mp2[it.second]++;
        }
        return true;
    }
};
