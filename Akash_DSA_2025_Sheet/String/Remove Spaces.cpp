class Solution {
  public:
    string removeSpaces(string& s) {
        // code here
        int n=s.size();
        string result;
        for(char &ch:s){
            if(ch!=' ')result+=ch;
        }
        return result;
    }
};
// 👉 Similar problems:
//  • Remove vowels
//  • Remove special characters
//  • Normalize strings
