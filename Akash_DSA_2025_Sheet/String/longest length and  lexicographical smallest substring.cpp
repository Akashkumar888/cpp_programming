
class Solution {
public:
    string longestWord(vector<string>& words) {
        string smallestString = "";
        for(string word:words){
           if (word.length() > smallestString.length()) {
                smallestString = word;
            } 
            else if (word.length()==smallestString.length() && word < smallestString) {
                smallestString = word;
            }
        }
        return smallestString;
    }
};

