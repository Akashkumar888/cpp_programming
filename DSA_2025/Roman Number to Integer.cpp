
class Solution {
  public:
  int solve(char &ch){
      if(ch=='I')return 1;
      else if(ch=='V')return 5;
      else if(ch=='X')return 10;
      else if(ch=='L')return 50;
      else if(ch=='C')return 100;
      else if(ch=='D')return 500;
      else if(ch=='M')return 1000;
  }
    int romanToDecimal(string &s) {
        // code here
        int n=s.size();
        if(n==1)return solve(s[0]); // singal char value 
        int number=0;
        int i=0;
        while(i<n-1){
            if(solve(s[i])<solve(s[i+1])){
            number+=(solve(s[i+1])-solve(s[i]));
            i+=2;    
            }
            else {
            number+=solve(s[i]);
            i++;
            }
        }
        if(i<n)number+=solve(s[i]);
        return number;
    }
};

// Time Complexity:
// Let n = length of the string s.
// In the worst case, you iterate through each character once.
// Inside each iteration, you call solve(s[i]) and solve(s[i+1]) — which are O(1) operations (just a switch/case check).

// So, overall time: O(n)
// Space Complexity:
// Only integer variables are used (number, i) — no extra data structures.

