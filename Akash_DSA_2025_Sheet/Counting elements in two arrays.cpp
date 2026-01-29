
class Solution {
  public:
    vector<int> countLessEq(vector<int>& a, vector<int>& b) {
        // code here
        int n=a.size();
        vector<int>ans;
        sort(b.begin(),b.end());
        for(int i=0;i<n;i++){
            int l=0,r=b.size()-1;
            int count=0;
            while(l<=r){
                int mid=l+(r-l)/2;
                if(a[i]>=b[mid]){
                    count=(mid+1);
                    l=mid+1;
                }
                else r=mid-1;
            }
            ans.push_back(count);
        }
        return ans;
    }
};

// 📦 Total Time Complexity: O(mlogm+nlogm)
// ​
// ✅ Space Complexity
// ans stores n elements → O(n)
// b is sorted in-place → O(1) extra
// No additional data structures used.


// To solve this problem in O(n + m) time and space, you can use a frequency array + prefix sum approach (often called counting sort technique).

// ✅ Key Idea (Optimal – No Sorting Needed)


class Solution {
  public:
    vector<int> countLessEq(vector<int>& a, vector<int>& b) {
        // code here
        int MAX_VAL = 1e5 + 1;
        vector<int> freq(MAX_VAL, 0);
        
        // Count frequency of each number in b[]
        for (int &x : b) {
            freq[x]++;
        }

        // Compute prefix sum to get count of <= x
        for (int i = 1; i < MAX_VAL; i++) {
            freq[i] += freq[i - 1];
        }

        vector<int> result;
        for (int &x : a) {
            result.push_back(freq[x]); // elements ≤ x
        }

        return result;
    }
};



// ✅ Time Complexity:
// O(m) to build frequency table from b[]
// O(MAX_VAL) to compute prefix sum (MAX_VAL = 1e5)
// O(n) to process all elements in a[]



// Total: O(n + m + MAX_VAL) → O(n + m)
// ✅ Space Complexity:
// O(MAX_VAL) → used for frequency array


