
class Solution {
  public:
// two strings s1 and s2, of equal lengths. The task is to check if s2 is a rotated version of the string s1.
// Note: A string is a rotation of another if it can be formed by moving characters from the start to the end (or vice versa) without rearranging them.
    bool areRotations(string &s1, string &s2) {
        // code here
        int n=s1.size();
        if(s1.size()!=s2.size())return false;
        // s1 ko rotate krna hai s2 banane ke liye.
        int count=0;
        // string:npos
        for(int i=0;i<n;i++){
            if(s1==s2)return true;
            char ch=s1.back();
            s1.pop_back();
            s1.insert(s1.begin(),ch);
        }
        return false;
    }
};

// ✅ Optimal & Standard Solution (O(n))
// 🔑 Key Idea
// If s2 is a rotation of s1, then s2 must be a substring of s1 + s1.
// Example
// s1 = "abcd"
// s1 + s1 = "abcdabcd"
// s2 = "cdab"  ✅ present → rotation


class Solution {
  public:
//   two strings s1 and s2, of equal lengths. The task is to check if s2 is a rotated version of the string s1.
// Note: A string is a rotation of another if it can be formed by moving characters from the start to the end (or vice versa) without rearranging them.
    bool areRotations(string &s1, string &s2) {
        // code here
        // s1 ko rotate krna hai s2 banane ke liye.
        if (s1.size() != s2.size()) return false;

        string temp = s1 + s1;
        return temp.find(s2) != string::npos;
    }
};


// 796. Rotate String
class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.size();
        if (n != goal.size()) return false;

        for (int i = 0; i < n; i++) {
            string rotated = s.substr(i) + s.substr(0, i);
            if (rotated == goal) return true;
        }
        return false;
    }
};


class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.size();
        if (n != goal.size()) return false;

        for (int i = 0; i < n; i++) {
            rotate(s.begin(), s.begin() + 1, s.end());
            if (s == goal) return true;
        }
        return false;
    }
};



class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.size() != goal.size()) return false;

        string temp = s + s;
        return temp.find(goal) != string::npos;
    }
};


// 🧠 NOW THE IMPORTANT PART: find() & string::npos
// 🔹 What does find() do?
// temp.find(goal)
// Returns the starting index where goal is found in temp
// If not found, it returns string::npos
// 🔹 What is string::npos?
// string::npos
// A constant meaning "NOT FOUND"
// Internally it is:
// size_t(-1)
// ❌ NOT equal to:
// -1
// 0
// 1
// 2
// 3
// ⚠️ DO NOT WRITE
// if (s.find(goal) != -1)   ❌ WRONG
// ✅ Correct Way
// if (s.find(goal) != string::npos)  // FOUND
// 🔹 Example
// string s = "abcdabcd";
// s.find("cdab");  // returns 2
// s.find("xyz");   // returns string::npos
// So:
// if (s.find("cdab") != string::npos) → true
// if (s.find("xyz") != string::npos)  → false


class Solution {
public:
    bool rotateString(string s, string goal) {
        int n=s.size();
        int m=goal.size();
        if(n!=m)return false;
        s=s+s;
        if(s.find(goal)!=-1)return true;
        return false;
    } 
};

// 5️⃣ Why sometimes == -1 appears to work 😵‍💫
// Example:
// if (s.find("xyz") == -1)
// Because:
// string::npos == size_t(-1)
// So by coincidence, it may work.
// ⚠️ But:
// This is NOT guaranteed
// Generates warnings
// Fails in strict compilation
// Considered bad C++
// 6️⃣ Why string::npos is the ONLY correct way ✅
// if (s.find(goal) == string::npos)
// ✔ Same type (size_t)
// ✔ Clear meaning
// ✔ Portable
// ✔ Safe
// ✔ Interview-acceptable
