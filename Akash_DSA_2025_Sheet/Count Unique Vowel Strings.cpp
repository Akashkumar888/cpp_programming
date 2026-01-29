

class Solution {
  public:
  bool isVowel(char &ch){
      return ch=='a' || ch=='e'||ch=='i'||ch=='o'||ch=='u';
  }
    int vowelCount(string& s) {
        // code here
        int n=s.size();
        int cnt=1;
        unordered_map<char,int>mp;
        for(char &ch:s){
            if(isVowel(ch)){
                mp[ch]++;
            }
        }
        int k=0;
        for(auto &it:mp){
            int freq=it.second;
            k++;
            cnt*=(freq);
        }
        if(k==0)return 0;
        int fact=1;
        for (int i=2;i<=k;i++) {
            fact *= i;
        }
        return cnt*fact;
    }
};

// ✅ 1. First Version (using unordered_map<char, int>)
// Time Complexity:
// O(n): You iterate through the string once.
// Accessing and updating unordered_map is average O(1) per operation.
// Calculating the result involves at most 5 multiplications (since there are 5 vowels), and a factorial for at most k=5, so constant time.
// Space Complexity:
// O(1): The map stores counts for at most 5 vowels — fixed size, constant auxiliary space.
// Pros:
// Code is clean and flexible.
// Works for any character input, not limited to the order of vowels.
// Easier to scale if more vowels or cases are added.
// Cons:
// Slight overhead of hashing in unordered_map compared to direct indexing.

class Solution {
  public:
  bool isVowel(char &ch){
      return ch=='a' || ch=='e'||ch=='i'||ch=='o'||ch=='u';
  }
  int getIndex(char ch) {
    if (ch == 'a') return 0;
    if (ch == 'e') return 1;
    if (ch == 'i') return 2;
    if (ch == 'o') return 3;
    if (ch == 'u') return 4;
    return -1; // shouldn't reach here
   }
    int vowelCount(string& s) {
        // code here
        int n=s.size();
        int cnt=1;
        vector<int>mp(5,0);
        for(char &ch:s){
            if(isVowel(ch)){
                mp[getIndex(ch)]++;
            }
        }
        int k=0;
        for(int i=0;i<5;i++){
            if(mp[i]>0){
            k++;    
            cnt*=(mp[i]);
            }
        }
        if(k==0)return 0;
        int fact=1;
        for (int i=2;i<=k;i++) {
            fact *= i;
        }
        return cnt*fact;
    }
};

// ✅ 2. Second Version (using vector<int>(5) and getIndex())
// Time Complexity:
// O(n): Same as first — you iterate over the string once.
// Vector indexing is O(1).
// Same fixed-time factorial computation and result aggregation.
// Space Complexity:
// O(1): Fixed-size vector of size 5.
// Pros:
// Slightly faster in practice due to direct array access (no hashing).
// Lower overhead than unordered_map.
// Cons:
// Less flexible — hardcoded index mapping through getIndex() makes it less readable and harder to maintain.
// Any changes to vowel set (like including uppercase or accented vowels) would require more updates.

