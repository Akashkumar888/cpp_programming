class Solution {
public:
    bool allNine(vector<int>& nums) {
        for(int &x : nums){
            if(x != 9)return false;
        }
        return true;
    }
    void mirror(vector<int>& res){
        int n=res.size();
        int i = 0;// i for left part 
        int j = n - 1;// j for right part
        while (i < j) {// it handles both odd and even number of elements in array
            res[j] = res[i];
            i++;
            j--;
        }
    }
    bool isGreater(vector<int>& res,vector<int>& nums) {
        int n=nums.size();
        for (int i = 0; i < n; i++) {
            if (res[i] > nums[i]) return true;
            else if (res[i] < nums[i]) return false;
        }
        return false;
    }
    void incrementMiddle(vector<int>& res) {
        int n = res.size();
        int carry = 1;
        int mid = n / 2;
        int i;// i for left part 
        int j;// j for right part
        if (n % 2 == 1) { // odd elements in array 
            res[mid] = res[mid] + carry;
            carry = res[mid] / 10;
            res[mid] = res[mid] % 10;
            i = mid - 1;// i for left part 
            j = mid + 1;// j for right part
        } 
        else {// even elements in array
            i = mid - 1;// i for left part
            j = mid;    // j for right part
        }
        while (i >= 0 && carry) {//next smallest palindrome strictly larger
            res[i] = res[i] + carry;
            carry = res[i] / 10;
            res[i] = res[i] % 10;
            res[j] = res[i]; 
            i--;
            j++;
        }
    }
    vector<int> nextPalindrome(vector<int>& nums) {
        int n = nums.size();
        // [9,9,9] -> [1,0,0,1]
        // ✅ Case 1: All 9
        if (allNine(nums)) {
            vector<int> res(n + 1, 0);
            res[0] = 1;
            res[n] = 1;
            return res;
        }
        vector<int> res = nums;

        // ✅ Step 1: Mirror
        mirror(res);

        // ✅ Step 2: Check if already greater
        if (isGreater(res, nums))return res;
        
        // ✅ Step 3: Increment middle
        incrementMiddle(res);

        return res;
    }
};
