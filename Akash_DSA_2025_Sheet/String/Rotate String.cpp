
class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size()!=goal.size())return false;
        s=s+s;
        // if(s.find(goal)==string::npos)return false;
        if(s.find(goal)==-1)return false;// if string not find then idx = -1 return if string found then idx return except -1 
        return true;
    }
};


class Solution {
public:
    bool rotateString(string s, string goal) {

        // If lengths are different, rotation is impossible
        if(s.size() != goal.size()) return false;

        // Concatenate string with itself
        // Example: "abc" → "abcabc"
        // All possible rotations of s will be present in this new string
        s = s + s;

        // Check if goal is a substring of s+s
        // string::find returns:
        //   - index (>=0) if found
        //   - string::npos if NOT found
        // NOTE: string::npos is NOT equal to -1 (important!)
        
        // ❌ Wrong: (s.find(goal) == -1)
        // ✅ Correct:
        if(s.find(goal) == string::npos) return false;

        return true;
    }
};
