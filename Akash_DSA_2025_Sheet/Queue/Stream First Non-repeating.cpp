class Solution {
  public:
    string firstNonRepeating(string &s) {
        int n = s.size();
        vector<int> freq(26, 0);   // frequency of characters
        queue<char> q;             // maintains stream order
        string ans = "";

        for (int i = 0; i < n; i++) {
            char ch = s[i];

            // increase frequency
            freq[ch - 'a']++;

            // push character into queue
            q.push(ch);

            // remove repeating characters from front
            while (!q.empty() && freq[q.front() - 'a'] > 1) {
                q.pop();
            }

            // store answer for current prefix
            if (q.empty())ans.push_back('#');
            else ans.push_back(q.front());
        }
        return ans;
    }
};




#include <iostream>
#include <string>
#include <vector>
using namespace std;

string firstNonRepeating(string &s){
    string ans;
    int n = s.size();
    
    // frequency vector for all ASCII characters
    vector<int> freq(26, 0);

    // Process each character in the stream
    for (int i = 0; i < n; i++){
        
        // Update frequency for the current character
        freq[s[i]-'a']++;

        // Scan from the beginning to find the first non-repeating character
        bool found = false;
        
        for (int j = 0; j <= i; j++){
            if (freq[s[j]-'a'] == 1){
                ans.push_back(s[j]);
                found = true;
                break;
            }
        }
        
        
        if (!found){
            ans.push_back('#');
        }
    }

    return ans;
}

int main() {
    string s = "aabc";
    string ans = firstNonRepeating(s);
    cout << ans << endl;
    return 0;
}







class Solution {
  public:
//   mp only stores frequency, not the order of arrival. that why we use queue 
// “First non-repeating” depends on stream order, not alphabetical order.
  char solve(queue<char>& q, vector<int>& mp) {
      while (!q.empty() && mp[q.front() - 'a'] > 1) {
          q.pop();
      }
      if (q.empty()) return '#';
      return q.front();
  }

  string firstNonRepeating(string &s) {
      int n = s.size();
      string result = "";
      vector<int> mp(26, 0);
      queue<char> q;

      for (int i = 0; i < n; i++) {
          char ch = s[i];
          mp[ch - 'a']++;
          q.push(ch);

          char ans = solve(q, mp);
          result.push_back(ans);
      }
      return result;
  }
};


class Solution {
  public:
//   mp only stores frequency, not the order of arrival. that why we use queue 
// “First non-repeating” depends on stream order, not alphabetical order.

  // mp only stores frequency, not the order of arrival. that why we use firstOccurence
  // “First non-repeating” depends on stream order, not alphabetical order.
  char solve(vector<int>& freq, vector<int>& firstOccurence){
      int bestIdx = INT_MAX;
      int bestChar = -1;

      for(int i = 0; i < 26; i++){
          if(freq[i] == 1 && firstOccurence[i] != -1){
              if(firstOccurence[i] < bestIdx){
                  bestIdx = firstOccurence[i];
                  bestChar = i;
              }
          }
      }
      if(bestChar == -1) return '#';
      return char(97 + bestChar);
  }
  string firstNonRepeating(string &s) {
      int n = s.size();
      vector<int> freq(26, 0);
      vector<int> firstOccurence(26, -1);
      string result = "";
      for(int i = 0; i < n; i++){
          int ch = s[i] - 'a';
          if(firstOccurence[ch] == -1){
              firstOccurence[ch] = i;   // store first time index
          }
          freq[ch]++;
          result += solve(freq, firstOccurence);
      }
      return result;
  }
};


