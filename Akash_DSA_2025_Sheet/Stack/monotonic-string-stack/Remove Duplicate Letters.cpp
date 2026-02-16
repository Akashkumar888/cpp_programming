
class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.size();
        vector<int> lastOccurrence(26, 0);
        vector<bool> visited(26, false);//remove duplicate letters so that every letter appears once and only once

        // store last occurrence
        for (int i = 0; i < n; i++) {
            lastOccurrence[s[i] - 'a'] = i;
        }
        stack<char> st;
        st.push(s[0]);
        visited[s[0] - 'a'] = true;

        for (int i = 1; i < n; i++) {
            char ch = s[i];
            if (visited[ch - 'a'])continue;

            while (!st.empty() && st.top() > ch && lastOccurrence[st.top() - 'a'] > i) {
                visited[st.top() - 'a'] = false;
                st.pop();
            }
            st.push(ch);
            visited[ch - 'a'] = true;
        }

        // Build result from stack
        string result = "";

        while (!st.empty()) {
            result += st.top();
            st.pop();
        }
        reverse(result.begin(), result.end());

        return result;
    }
};


// This is about string memory behavior, not stack logic.
// You asked:

// while (!st.empty()) {
//     result = st.top() + result;
//     st.pop();
// }


// Why does this cause MLE / TLE, but using reverse() works fine?
// 🔥 The Real Reason: String Concatenation Cost
// When you do:
// result = st.top() + result;
// You are inserting a character at the front of string.
// That means:
// New memory allocated
// Entire old string copied
// New character inserted at front
// If result size = k
// Each operation costs O(k)
// 🧠 Time Complexity Analysis
// Suppose final string length = n
// Operations:

// 1 char  → O(1)
// 2 chars → O(2)
// 3 chars → O(3)
// ...
// n chars → O(n)

// Total:
// 1 + 2 + 3 + ... + n
// = O(n²)

// 🚨 So this becomes O(n²)
// For large input → TLE or MLE.
// 🔥 Why Reverse Is Better

// Instead do:
// while(!st.empty()) {
//     result += st.top();   // append at end
//     st.pop();
// }
// reverse(result.begin(), result.end());

// Appending at end:
// Amortized O(1)
// Total O(n)
// Reverse:  O(n)
// So total:
// O(n) + O(n) = O(n)

// ✔ Safe
// ✔ Fast
// ✔ No memory explosion
// 🔥 Why Front Insert Is Expensive?
// Because C++ string is internally a dynamic array.
// Inserting at front requires shifting all elements.
// Same reason why:
// vector.insert(begin(), x); is O(n)
// 🧠 Interview Insight
// If interviewer asks:
// Why reverse instead of inserting at front?
// You say:
// "Prepending to a string is O(n) because it requires shifting all characters. Repeating this inside a loop results in O(n²) complexity. Appending followed by a single reverse keeps total time complexity O(n)."
// That answer sounds very strong 🔥
// 🚀 Even Better Way (No Reverse Needed)
// Use string as stack:
// string st = "";
// st.push_back(ch);
// st.pop_back();
// Then just return st.
// No reverse.
// No extra loop.
// Best approach.

class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.size();
        vector<int> lastOccurrence(26, 0);
        vector<bool> visited(26, false);//remove duplicate letters so that every letter appears once and only once

        // store last occurrence
        for (int i = 0; i < n; i++) {
            lastOccurrence[s[i] - 'a'] = i;
        }
        string st="";
        st.push_back(s[0]);
        visited[s[0] - 'a'] = true;

        for (int i = 1; i < n; i++) {
            char ch = s[i];
            if (visited[ch - 'a'])continue;

            while (!st.empty() && st.back() > ch && lastOccurrence[st.back() - 'a'] > i) {
                visited[st.back() - 'a'] = false;
                st.pop_back();
            }
            st.push_back(ch);
            visited[ch - 'a'] = true;
        }

        return st;
    }
};