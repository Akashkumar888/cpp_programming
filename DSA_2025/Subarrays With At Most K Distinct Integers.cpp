
class Solution {
  public:
    int countAtMostK(vector<int> &arr, int k) {
        // code here
        int n=arr.size();
        unordered_map<int,int>mp;
        int i=0,j=0;
        int count=0;
        while(j<n){
            mp[arr[j]]++;
            while(mp.size()>k){
                mp[arr[i]]--;
                if(mp[arr[i]]==0)mp.erase(arr[i]);
                i++;
            }
            count+=(j-i+1); // count distinct subarray
            j++;
        }
        return count;
    }
};

// ⏱️ Time Complexity
// Each element is added and removed from the map at most once → So the outer and inner loops run in total O(n) time.
// Map operations (insert, delete, access) are average-case O(1) for unordered_map.
// 🔹 Overall Time Complexity: O(n)
// Where n = arr.size()

// 💾 Space Complexity
// In the worst case, the map can hold up to k distinct elements.
// 🔹 Space Complexity: O(k)

