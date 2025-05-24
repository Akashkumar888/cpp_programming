class Solution {
  public:
    int sumSubstrings(string &s) {
        // code here
    int n = s.size();
    int totalSum = 0;
    int prevSum = 0;
    for (int i = 0; i < n; i++) {
        int num = s[i] - '0';
        prevSum = prevSum * 10 + (i + 1) * num;
        totalSum += prevSum;
    }
    return totalSum;  
    }
};



class Solution {
  public:
    int sumSubstrings(string &s) {
        // code here
        int n=s.size();
        int totalSum=0;
        int mf=1;
      for(int i=n-1;i>=0;i--){
          totalSum+=(s[i]-'0')*(i+1)*mf;
          mf=mf*10+1;
      }
     return totalSum;  
    }
};




