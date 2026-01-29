
class Solution {
  public:
  void solve(int i,string &s,long long val,long prev,int target,string &expr,vector<string>&result) {
      if(i==s.size()) {
          if(val==target)result.push_back(expr);
          return;
      }
      for(int j=i;j<s.size();j++) {
          // avoid numbers with leading zero
          if(j>i && s[i]=='0') break;
          
          string part = s.substr(i,j-i+1);
          long cur=stol(part); // string to long like stoi 
          int len=expr.size();
          
          if(i == 0) {
              // first number, no operator
              expr += part;
              solve(j+1,s,cur,cur,target,expr,result);
              expr.resize(len);
          } 
          else {
              // "+"
              expr += "+" + part;
              solve(j+1, s, val + cur, cur, target, expr, result);
              expr.resize(len);
              
              // "-"
              expr += "-" + part;
              solve(j+1, s, val - cur, -cur, target, expr, result);
              expr.resize(len);
              
              // "*"
              expr += "*" + part;
              solve(j+1, s, val - prev + prev * cur, prev * cur, target, expr, result);
              expr.resize(len);
          }
      }
  }
  vector<string> findExpr(string &s, int target) {
      vector<string> result;
      string expr = "";
      solve(0, s, 0, 0, target, expr, result);
      return result;
  }
};

// ✅ Key Idea
// curr → number you’re currently adding (+), subtracting (-), multiplying (*), or dividing (/).
// prev → what was last added/subtracted to val (used to undo & reapply for * and /).
// Think of it as curr = do, prev = undo/adjust for precedence.

// BODMAS Rule
// + and - don’t cause issues, because they evaluate left-to-right naturally.
// But * (and /) have higher precedence, so you can’t just val * cur.
// Instead, you undo the last operation (val - prev), and then apply multiplication/division with the last operand.

// 🔹 Multiplication (*)

// Formula:
// val = val - prev + prev * cur;
// prev = prev * cur;

// ✔ Works because it replaces the last operand with its multiplied version.


// 🔹 Division (/)

// Formula:
// // careful about divide by zero
// if(cur != 0) {
//     val = val - prev + prev / cur;
//     prev = prev / cur;
// }


// If cur == 0, then prev / cur is undefined, so we must skip that branch in backtracking.
// ✅ What to do when cur == 0

// Simply do not explore the / option:
// // "/"
// if(cur != 0) {   // ✅ skip division by zero
//     expr += "/" + part;
//     solve(j+1, s, val - prev + prev / cur, prev / cur, target, expr, result);
//     expr.resize(len);
// }
