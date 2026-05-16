
class Solution {
public:
//   xor is a reserved keyword in C++, so you cannot use it as a variable name.
  void solve(int i,int n,vector<int>&nums,int &totalXor,int &sum){
      if(i>=n){
          sum+=totalXor;
          return;
      }
      totalXor^=nums[i];// take xor of arr[i]
      solve(i+1,n,nums,totalXor,sum);// explore
      totalXor^=nums[i];// remove from xor 
      solve(i+1,n,nums,totalXor,sum);// explore
  }
    int subsetXORSum(vector<int>& nums) {
        long long OR = 0;
        int n = nums.size();
        
        for (int &x : nums)
            OR |= x;

        return OR * (1LL << (n - 1));
    }
};


class Solution {
public:
//   xor is a reserved keyword in C++, so you cannot use it as a variable name.
  void solve(int i,int n,vector<int>&nums,int &totalXor,int &sum){
      if(i>=n){
          sum+=totalXor;
          return;
      }
      totalXor^=nums[i];// take xor of arr[i]
      solve(i+1,n,nums,totalXor,sum);// explore
      totalXor^=nums[i];// remove from xor 
      solve(i+1,n,nums,totalXor,sum);// explore
  }
    int subsetXORSum(vector<int>& nums) {
        int n=nums.size();
        // generate all subsets using backtrack
        int sum=0,totalXor=0;
        solve(0,n,nums,totalXor,sum);
        return sum;
    }
};


class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
    int n = nums.size();
    int OR = 0;
    // Finding bitwise OR of all elements
    for (int &num:nums)OR |= num;
    int ans = OR * (1<<(n-1)); // append n-1 zeroes right hand side
    return ans;
    }
};



class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
    int n = nums.size();
    int bits = 0;
    // Finding bitwise OR of all elements
    for (int &num:nums)bits |= num;
    int ans = bits * pow(2, n-1);
    return ans;
    }
};


class Solution {
public:
void solve(int i,int n,int &XOR,int &sum,vector<int>&nums){
    if(i>=n){
        sum+=XOR;
        return;
    }
    // pick do
    XOR=XOR^nums[i]; // xor ko lo 
    solve(i+1,n,XOR,sum,nums);
    // notpick undo 
    XOR=XOR^nums[i]; // xor ko hatao 
    solve(i+1,n,XOR,sum,nums);
}
    int subsetXORSum(vector<int>& nums) {
    int n=nums.size();
    int sum=0;
    int XOR=0;
    solve(0,n,XOR,sum,nums);
    return sum;
    }
};

