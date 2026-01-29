
class Solution {
  public:
    vector<int> asciirange(string& s) {
        // code here
        int n=s.size();
        vector<int>ans;
        vector<int>last_idx(26,-1);
        for(int i=0;i<n;i++){
            last_idx[s[i]-'a']=i;
        }
        vector<int>preSum(n,0);
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=int(s[i]);
            preSum[i]=sum;
        }
        int currSum=0;
        for(int i=0;i<n;i++){
            int idx=last_idx[s[i]-'a'];
            if(idx!=i &&idx!=-1){
                int val=preSum[idx];
                int d=(s[i]);
                int non_zero=val-2*d-currSum;
                if(non_zero)ans.push_back(non_zero);
                last_idx[s[i]-'a']=-1;
            }
            currSum+=s[i];
        }
        return ans;
    }
};

// 🔹Time Complexity:
// First loop: O(n) → fills last_idx
// Second loop: O(n) → builds preSum
// Third loop: O(n) → processes each character to check and compute result
// ✅ Total: O(n)

// 🔹Space Complexity (excluding ans):
// last_idx: O(26) → constant, so O(1)
// preSum: O(n)
// Other variables: O(1)
// ✅ Total: O(n)



class Solution {
  public:
    vector<int> asciirange(string& s) {
        // code here
        int n=s.size();
        vector<int>ans;
        vector<pair<int,int>>last_idx(26,{-1,-1});
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=int(s[i]);
            last_idx[s[i]-'a']={i,sum};
        }
        int currSum=0;
        for(int i=0;i<n;i++){
            int idx=last_idx[s[i]-'a'].first;
            if(idx!=i &&idx!=-1){
                int val=last_idx[s[i]-'a'].second;
                int d=(s[i]);
                int non_zero=val-2*d-currSum;
                if(non_zero)ans.push_back(non_zero);
                last_idx[s[i]-'a'].first=-1;
            }
            currSum+=s[i];
        }
        return ans;
    }
};

// 🔹Time Complexity:
// First loop: O(n) → builds last_idx with index and ASCII sum
// Second loop: O(n) → processes each character using last_idx
// ✅ Total: O(n)

// 🔹Space Complexity (excluding ans):
// last_idx: O(26) → constant → O(1)
// No preSum vector like in 1st code
// Other variables: O(1)
// ✅ Total: O(1)

