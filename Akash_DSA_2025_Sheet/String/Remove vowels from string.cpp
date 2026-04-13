// User function template for C++
class Solution {
  public:
    string removeVowels(string& s) {
        // Your code goes here
        int n=s.size();
        string result;
        for(char &ch:s){
            if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u')continue;
            else result+=ch;
        }
        return result;
    }
};
