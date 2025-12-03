// ✔ XOR is:

// Associative
// (a ^ b) ^ c = a ^ (b ^ c)

// Commutative
// a ^ b = b ^ a

// Self-inverse / Reversible
// a ^ a = 0
// a ^ b ^ b = a


// XOR is reversible, not transitive.

// a ^ b = c  
// ⇒ c ^ b = a  
// ⇒ c ^ a = b

// This works because XOR undoes itself.
class Solution {
public:
 int solve(int n){ //well-known XOR-prefix formula.
      if(n%4==1)return 1;
      else if(n%4==2)return n+1;
      else if(n%4==3)return 0;
      else if(n%4==0)return n;
  }
    vector<int> subsetXOR(int n) {
        vector<int> ans;
        if(n==1) return {1};
        for(int i=1;i<=n;i++)ans.push_back(i);
        int allXor=solve(n);
        if(allXor==n)return ans;
        int newXor=allXor ^ n;
        // newXor = T ^ x = n
        // → x = T ^ n
        // This is EXACT reversible XOR logic.
        vector<int>result;
        for(int &num:ans){
            if((num^allXor)==n)continue;
            else result.push_back(num);
        }
        return result;
    }
};



class Solution {
public:
    vector<int> subsetXOR(int n) {
        vector<int> ans;
        if(n==1) return {1};
        for(int i=1;i<=n;i++){
            ans.push_back(i);
        }
        if(n%4 == 1) ans.erase(ans.begin() + n - 2); 
        if(n%4 == 2) ans.erase(ans.begin());        
        if(n%4 == 3) ans.erase(ans.begin() + n - 1);        
        return ans ;
    }
};

// ✅ LINE–BY–LINE EXPLANATION of subsetXOR
// vector<int> subsetXOR(int n) {

// ✔ Function returns a subset whose XOR = n.
// vector<int> ans;

// ✔ Create an empty answer vector.
// if(n == 1) return {1};

// ✔ Special case:

// For n = 1, the only subset is {1}, and its XOR = 1.

// for(int i = 1; i <= n; i++){
//     ans.push_back(i);
// }

// ✔ Build full list:

// ans = {1, 2, 3, ..., n}
// This contains every number from 1 to n.

// Later we will remove exactly ONE element to make XOR = n.

// 🔥 WHY REMOVE ONE ELEMENT?

// Let:

// T = XOR(1..n)


// To make final XOR = n:

// T ^ removed_element = n
// → removed_element = T ^ n


// Your code removes that exact element depending on n % 4.

// ⭐ CASE ANALYSIS BASED ON (n % 4)
// ✔ XOR(1..n) pattern:

// 🎯 Summary Table
// n%4	                      XOR(1..n)	                           Element to remove	                        Your code  removes	                 Why
//  0                          n                                   none                                       none                                 full set XOR = n
// 1                           1                                   n−1                                        ans[n−2]                             (1 ^ n = n−1)
// 2                          n+1                                  1                                          ans[0]                               ((n+1) ^ n = 1)
// 3                          0                                    n                                          ans[n−1]                             (0 ^ n = n)
// ✔ Perfect match for all cases
// ✔ That’s why your code works

// 🎉 Final Conclusion
// Your solution is using a perfect mathematical trick:
// “Compute XOR(1..n), remove exactly the element needed so that remaining XOR = n”
// This works because:
// XOR behaves predictably in 1..n based on n%4
// Removing exactly T ^ n (where T = XOR(1..n)) produces XOR = n
// Your code removes that element in all cases