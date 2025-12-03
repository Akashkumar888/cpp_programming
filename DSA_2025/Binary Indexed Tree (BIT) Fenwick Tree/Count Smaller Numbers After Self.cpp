
// LeetCode Problem 315
// Use BIT to maintain frequencies of future numbers.

class BIT {
public:
    vector<int> bit;
    int n;
    BIT(int n) {
        this->n = n;
        bit.resize(n+1, 0);
    }
    // add value at index i
    void update(int i, int val) {
        while(i <= n) {
            bit[i] += val;
            i += (i & -i);
        }
    }
    // prefix sum
    int query(int i) {
        int sum = 0;
        while(i > 0) {
            sum += bit[i];
            i -= (i & -i);
        }
        return sum;
    }
    // range sum L..R
    int rangeQuery(int L, int R) {
        return query(R) - query(L - 1);
    }
};

class Solution {
public:
int lowerbound(vector<int>&temp,int tr){
    int l=0,r=temp.size()-1, idx=temp.size();
    while(l<=r){
        int mid=l+(r-l)/2;
        if(temp[mid] >= tr){
            idx = mid;
            r = mid-1;
        }else{
            l = mid+1;
        }
    }
    return idx + 1;  // convert to 1-based index for BIT
}

    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> temp = nums;
        sort(temp.begin(), temp.end());
        temp.erase(unique(temp.begin(), temp.end()), temp.end());
        
        int m = temp.size();
        BIT bit(m);
        
        vector<int> result(n,0);
        
        for(int i = n-1; i >= 0; i--) {
            // coordinate compression index (1-based)
            int idx = lowerbound(temp, nums[i]);
            
            // count of smaller elements = all elements < idx
            result[i] = bit.query(idx - 1);
            
            // update BIT with this element
            bit.update(idx, 1);
        }
        return result;
    }
};

