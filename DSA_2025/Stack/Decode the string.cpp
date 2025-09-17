

class Solution {
  public:
    string decodedString(string &s) {
        stack<string> strStack;
        stack<int>numbers;
        string result="";
        int num = 0;
// Most decoding solutions parse left-to-right, not right-to-left.
// If you traverse from the back, your digit parsing (k = k*10 + (s[i]-'0')) will not build numbers correctly.
        for (char &ch : s){
            if (ch>='0' && ch<='9') {
                num = num * 10 + (ch-'0'); // build number
            } 
            else if (ch == '[') {
               if(num>0)numbers.push(num);
                strStack.push(result); // ek bar "" string bhi push kr rahe hai 
                num = 0;
                result = "";
            } 
            else if (ch == ']') {
                int repeat = numbers.top();
                numbers.pop();
                string prev = strStack.top(); // last time prev =""
                strStack.pop();
                string temp = "";
                for (int i=0;i<repeat;i++) {
                    temp = temp + result;
                }
                result = prev + temp; // merge with previous
                // last time prev ="" result me add kr rahe hai jisse answer pr koi fark nhi padega
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
                // It doesn’t fill the string with characters, it only reserves memory capacity.
                // Final temp = "abcabcabcabc"
                // reserve 3*4 = 12 characters in advance
                // Now, temp pre-allocates space for 12 characters.
              // Appending happens without repeated reallocation/copying.
                for (int i = 0; i < repeat; i++) {
                    temp.append(result);   // appends without reallocation
                    // each append(result) copies "ab" into the end of temp until you reach the repeat count.
                    // temp += result;
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
