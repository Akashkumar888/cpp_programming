
// consonants - vowels or vowels - consonants: both are fine, just be consistent.

class Solution {
  public:
  bool isVowel(char &ch){
      return ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u';
  }
    int countBalanced(vector<string>& arr) {
        // code here
        int n=arr.size();
        unordered_map<int,int>mp;
        mp[0]=1;
        int count=0;
        int preSum=0;
        for(string &str:arr){
        int vowel=0,consonants=0;
            for(char &ch:str){
                if(isVowel(ch))vowel++;
                else consonants++;
            }
            // (consonants - vowels) or (vowels - consonants): both are fine, just be consistent.
            // preSum+=consonants-vowel;
            preSum+=vowel-consonants;
            if(mp.find(preSum)!=mp.end())count+=mp[preSum];
            mp[preSum]++;
        }
        return count;
    }
};



// ⏱ Time Complexity:
// Let's break it down:
// Let n = number of strings in arr
// Let L = average length of a string
// T(n, L) = O(n * L)

// 🧠 Space Complexity:
// unordered_map<int, int> → at most O(n) different preSum values (in worst case)
// No extra space per string except loop variables
// S(n) = O(n)


