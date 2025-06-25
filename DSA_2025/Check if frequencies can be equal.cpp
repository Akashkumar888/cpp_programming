
class Solution {
  public:
    bool sameFreq(string& s) {
        // code here
       vector<int> freq(26, 0);
        for (char &ch : s) freq[ch - 'a']++;

        vector<int> counts;
        for (int &f : freq)
            if (f > 0) counts.push_back(f);

        sort(counts.begin(), counts.end());

        // Case 1: All same
        if (counts.front() == counts.back()) return true;

        // Case 2: One high freq > rest by 1, and appears once
        if (counts.back() - counts[counts.size() - 2] == 1 &&
            count(counts.begin(), counts.end(), counts.back()) == 1 &&
            counts[counts.size() - 2] == counts.front()) {
            return true;
        }

        // Case 3: One freq is 1 and occurs once, rest equal
        if (counts[0] == 1 && count(counts.begin(), counts.end(), 1) == 1 &&
            counts[1] == counts.back()) {
            return true;
        }

        return false;
    }
};
