
// 🔥 2️⃣ Optimal Approach (Prefix XOR + HashMap)
// 💡 Key Observation
// Let:
// prefixXOR[i] = XOR of elements from index 0 to i
// For a subarray from l to r:
// XOR(l → r) = prefixXOR[r] ^ prefixXOR[l-1]
// We want:
// prefixXOR[r] ^ prefixXOR[l-1] = k
// Rearrange:
// prefixXOR[l-1] = prefixXOR[r] ^ k
// 🧠 What This Means
// At index r:
// If we know how many times
// prefixXOR[r] ^ k appeared before,
// then those many subarrays end at r with XOR = k.



class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        // code here
        int n=arr.size();
        vector<int>prefixXOR(n,0);
        prefixXOR[0]=arr[0];
        for(int i=1;i<n;i++){
            prefixXOR[i]=prefixXOR[i-1]^arr[i];
        }
        long long count=0;
        unordered_map<int,int>mp;
        // Step 2: Traverse prefix array
        for(int i = 0; i < n; i++){
            // Case 1: Subarray from 0 to i
            if(prefixXOR[i] == k)count++;
            
            // XOR(l → r) = prefixXOR[r] ^ prefixXOR[l-1]
            // We want:
            // prefixXOR[r] ^ prefixXOR[l-1] = k
            // Rearrange:
            // prefixXOR[l-1] = prefixXOR[r] ^ k
            // Case 2: Check required prefix
            int required = prefixXOR[i] ^ k;
            if(mp.find(required) != mp.end())count += mp[required];
            // Store current prefix
            mp[prefixXOR[i]]++;
        }
        return count;
    }
};
