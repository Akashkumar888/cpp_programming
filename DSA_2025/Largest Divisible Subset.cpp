

class Solution {
  public:
    vector<int> largestSubset(vector<int>& arr) {
        // Code here
        int n=arr.size();
        sort(arr.begin(),arr.end());
        int maxi=1;
        int last_idx=0;
        vector<int>dp(n,1);
        vector<int>hash(n); // for store idx of element 
       for(int i=0;i<n;i++){
           hash[i]=i;
           for(int j=0;j<=i-1;j++){
               if((arr[i]%arr[j]==0) && dp[i]<dp[j]+1){
                   dp[i]=dp[j]+1;
                   hash[i]=j;
               }
           }
           if(dp[i]>maxi){
               maxi=dp[i];
               last_idx=i;
           }
       }
       vector<int>ans;
       ans.push_back(arr[last_idx]);
       while(hash[last_idx]!=last_idx){
           last_idx=hash[last_idx];
           ans.push_back(arr[last_idx]);
       }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};


// Note : If multiple subsets of the same maximum length exist, return the one that is lexicographically greatest, after sorting the subset in ascending order.

class Solution {
  public:
    vector<int> largestSubset(vector<int>& arr) {
        // Code here
        int n=arr.size();
        sort(arr.rbegin(),arr.rend()); // reverse sort 
        int maxi=1;
        int last_idx=0;
        vector<int>dp(n,1);
        vector<int>hash(n); // for store idx of element 
       for(int i=0;i<n;i++){
           hash[i]=i;
           for(int j=0;j<i;j++){
               if((arr[j]%arr[i]==0) && dp[i]<dp[j]+1){
                   dp[i]=dp[j]+1;
                   hash[i]=j;
               }
           }
           // 🔥 Choose lexicographically greatest 
            if (dp[i] > maxi) {
                maxi = dp[i];
                last_idx = i;
            }
       }

       vector<int>ans;
       ans.push_back(arr[last_idx]);
       while(hash[last_idx]!=last_idx){
           last_idx=hash[last_idx];
           ans.push_back(arr[last_idx]);
       }
        return ans;
    }
};




// print lis 

class Solution {
public:
    vector<int> LIS(vector<int>& arr) {
        int n = arr.size();
        vector<int> dp(n, 1);
        vector<int> hash(n);
        int maxi = 1;
        int last_idx = 0;

        for (int i = 0; i < n; i++) {
            hash[i] = i;  // by default each element starts its own subsequence
            for (int j = 0; j < i; j++) {
                if (arr[i] > arr[j] && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    hash[i] = j;
                }
            }

            if (dp[i] > maxi) {
                maxi = dp[i];
                last_idx = i;
            }
        }

        vector<int> ans;
        ans.push_back(arr[last_idx]);
        while (hash[last_idx] != last_idx) {
            last_idx = hash[last_idx];
            ans.push_back(arr[last_idx]);
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};



