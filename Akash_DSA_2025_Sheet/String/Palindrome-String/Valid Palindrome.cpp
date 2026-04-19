
class Solution {
public:
    bool isPalindrome(string s) {
        int n=s.size();
        int i=0,j=n-1;
        while(i<j){
        while(i<j && !isalnum(s[i]))i++;
        while(i<j && !isalnum(s[j]))j--;
        if(tolower(s[i])!=tolower(s[j]))return false;
        i++;
        j--;
        }
        return true;
    }
};

// islower(char): Checks if a character is a lowercase letter (a-z).
// isupper(char): Checks if a character is an uppercase letter (A-Z)

// tolower(char): Converts an uppercase letter to its lowercase equivalent.
// toupper(char): Converts a lowercase letter to its uppercase
