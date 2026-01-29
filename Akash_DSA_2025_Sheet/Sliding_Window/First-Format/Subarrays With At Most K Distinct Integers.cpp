
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
            count+=(j-i+1);// count distint subarray from i to j
            j++;
        }
        return count;
    }
};


class Solution {
  public:
    int countAtMostK(vector<int> &arr, int k) {
        int n = arr.size();
        unordered_map<int,int> mp; // stores frequency of elements
        int i = 0, j = 0;
        int count = 0;

        while (j < n) {
            mp[arr[j]]++;  // include current element

            // shrink window if distinct elements exceed k
            while (mp.size() > k) {
                mp[arr[i]]--;
                if (mp[arr[i]] == 0)
                    mp.erase(arr[i]);
                i++;
            }

            // number of valid subarrays ending at j
            count += (j - i + 1);

            j++;
        }
        return count;
    }
};

