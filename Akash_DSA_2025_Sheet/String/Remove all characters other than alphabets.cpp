// User function template for C++
class Solution {
  public:
    string removeSpecialCharacter(string s) {
        // code here
        int n=s.size();
        string result;
        for(char &ch:s){
            if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z')){
                result+=ch;
            }
        }
        return result.empty()?"-1":result;
    }
};
