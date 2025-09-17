

class Solution {
  public:
    string decodedString(string &s) {
        stack<string> strStack;
        stack<int> numStack;
        string result = "";
        int num = 0;
// Most decoding solutions parse left-to-right, not right-to-left.
// If you traverse from the back, your digit parsing (k = k*10 + (s[i]-'0')) will not build numbers correctly.
        for (char &ch : s) {
            if (ch>='0' && ch<='9') {
                num = num * 10 + (ch-'0'); // build number
            } 
            else if (ch == '[') {
                numStack.push(num);
                strStack.push(result);
                num = 0;
                result = "";
            } 
            else if (ch == ']') {
                int repeat = numStack.top();
                numStack.pop();
                string prev = strStack.top(); 
                strStack.pop();
                string temp = "";
                for (int i=0;i<repeat;i++) {
                    temp = temp + result;
                }
                result = prev + temp; // merge with previous
            } 
            else if(ch>='a' && ch<='z') {
                result += ch; // normal character
            }
        }
        return result;
    }
};


// ✅ Final Answer

// Time Complexity: O(n + L)
// Space Complexity: O(L)
// where
// n = length of input string
// L = length of fully decoded string

class Solution {
  public:
    string decodedString(string &s) {
        stack<string> strStack;
        stack<int> numStack;
        string result = "";
        int num = 0;
// Most decoding solutions parse left-to-right, not right-to-left.
// If you traverse from the back, your digit parsing (k = k*10 + (s[i]-'0')) will not build numbers correctly.
        for (char &ch : s) {
            if (ch>='0' && ch<='9') {
                num = num * 10 + (ch-'0'); // build number
            } 
            else if (ch == '[') {
                numStack.push(num);
                strStack.push(result);
                num = 0;
                result = "";
            } 
            else if (ch == ']') {
                int repeat = numStack.top();
                numStack.pop();
                string prev = strStack.top(); 
                strStack.pop();
                string temp;
                temp.reserve(result.size() * repeat); // preallocate memory once
                for (int i = 0; i < repeat; i++) {
                    temp.append(result);   // appends without reallocation
                }
                result = prev + temp; // merge with previous
            } 
            else if(ch>='a' && ch<='z') {
                result += ch; // normal character
            }
        }
        return result;
    }
};
