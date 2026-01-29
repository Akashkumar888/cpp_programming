
class Solution {
  public:
    bool isPalinSent(string &s) {
        // code here
        int n=s.size();
        int i=0,j=n-1;
        while(i<=j){
            // Skip non-alphanumeric characters
            // removing all non-alphanumeric characters
            while(i<j && !isalnum(s[i]))i++;
            while(i<j && !isalnum(s[j]))j--;
            if(tolower(s[i]) != tolower(s[j]))return false;
            // after converting all uppercase letters to lowercase 
            i++;
            j--;
        }
        return true;
    }
};
