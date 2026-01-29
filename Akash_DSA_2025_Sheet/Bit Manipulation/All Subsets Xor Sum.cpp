
class Solution {
  public:
//   xor is a reserved keyword in C++, so you cannot use it as a variable name.
  void solve(int i,int n,vector<int>&arr,int &totalXor,int &sum){
      if(i>=n){
          sum+=totalXor;
          return;
      }
      totalXor^=arr[i];// take xor of arr[i]
      solve(i+1,n,arr,totalXor,sum);// explore
      totalXor^=arr[i];// remove from xor 
      solve(i+1,n,arr,totalXor,sum);// explore
  }
    int subsetXORSum(vector<int>& arr) {
        // code here
        int n=arr.size();
        // generate all subsets using backtrack
        int sum=0,totalXor=0;
        solve(0,n,arr,totalXor,sum);
        return sum;
    }
};

// ⭐ Core Idea
// For every bit position, if a bit is 1 in at least one element, then:
// That bit will appear in exactly half of all subsets
// → i.e., in 2^(n – 1) subsets.
// And XOR is computed bit-by-bit, so we can compute the contribution of each bit independently.
class Solution {
  public:
    int subsetXORSum(vector<int>& arr) {
        // code here
        long long OR = 0;
        int n = arr.size();
        
        for (int &x : arr)
            OR |= x;

        return OR * (1LL << (n - 1));
    }
};
