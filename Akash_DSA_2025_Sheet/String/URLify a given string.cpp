class Solution {
  public:
    string URLify(string &s) {
        // code here
        string result="";
        if(s[0]==' ')result+="%20";
        for(char &ch:s){
            if(ch!=' ')result+=ch;
            else result+="%20";
        }
        return result;
    }
};
