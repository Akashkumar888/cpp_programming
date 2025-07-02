
class Solution {
  public:
    int totalElements(vector<int> &arr) {
        // code here
        int n=arr.size();
        unordered_map<int,int>mp;
        int maxlen=0;
        int i=0,j=0;
        while(j<n){
            mp[arr[j]]++;
            while(mp.size()>2){
                mp[arr[i]]--;
                if(mp[arr[i]]==0)mp.erase(arr[i]);
                i++;
            }
            maxlen=max(maxlen,j-i+1);
            j++;
        }
        return maxlen;
    }
};

// ✅ Time and Space Complexity:
// Time Complexity: O(n)
// Every element is inserted and removed from the map at most once.

// Space Complexity: O(1) (since mp holds at most 2 keys, which is constant)



