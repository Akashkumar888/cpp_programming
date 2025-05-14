
class Solution {
  public:
    string countAndSay(int n) {
        // code here
        if(n==1)return "1";
        string str=countAndSay(n-1);
        string ans="";
        int i=0;
        while(i<str.size()){
            char ch=str[i];
            int count=1;
            while(i<str.size()-1 && ch==str[i+1]){
                count++;
                i++;
            }
            ans=ans+to_string(count)+ch;
            i++;
        }
        return ans;
    }
  };

  