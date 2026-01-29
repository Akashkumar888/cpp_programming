
class Solution {
  public:
    vector<string> generateBinary(int n) {
        // code here
        vector<string>ans;
        for(int i=1;i<=n;i++){
            int bits=floor(log2(i)+1);
            string s="";
            for(int j=0;j<bits;j++){
                if((i&(1<<j)))s="1"+s;
                else s="0"+s;
            }
            ans.push_back(s);
        }
        return ans;
    }
};


class Solution {
  public:
    string toBinary(int num) {
        string s = "";
        while (num > 0) {
            s = char('0' + num % 2) + s;
            num /= 2;
        }
        return s;
    }
    
    vector<string> generateBinary(int n) {
        vector<string> ans;
        for (int i = 1; i <= n; i++) {
            ans.push_back(toBinary(i));
        }
        return ans;
    }
};
