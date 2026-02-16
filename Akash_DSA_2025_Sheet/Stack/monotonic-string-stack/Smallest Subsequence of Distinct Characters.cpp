

class Solution {
public:
    string smallestSubsequence(string s) {
        int n = s.size();
        vector<int> lastOccurrence(26, 0);
        vector<bool> visited(26, false);

        // store last occurrence
        for(int i = 0; i < n; i++){
            lastOccurrence[s[i] - 'a'] = i;
        }

        stack<char> st;
        st.push(s[0]);
        visited[s[0] - 'a'] = true;

        for(int i = 1; i < n; i++){
            char ch = s[i];
            
            if(visited[ch - 'a']) continue;
            
            while(!st.empty() && st.top() > ch && lastOccurrence[st.top() - 'a'] > i){
                visited[st.top() - 'a'] = false;
                st.pop();
            }
            st.push(ch);
            visited[ch - 'a'] = true;
        }
        
        // Build result from stack
        string result = "";
        
        while(!st.empty()){
            result += st.top();
            st.pop();
        }
        reverse(result.begin(), result.end());

        return result;
    }
};


// 🔥 If You Want More Optimal (Using String as Stack — Recommended)
// This is cleaner and interview-preferred:

class Solution {
public:
    string smallestSubsequence(string s) {
        int n = s.size();
        
        vector<int> lastOccurrence(26, 0);
        vector<bool> visited(26, false);
        
        for(int i = 0; i < n; i++){
            lastOccurrence[s[i] - 'a'] = i;
        }
        
        string st = "";   // using string as stack
        
        for(int i = 0; i < n; i++){
            char c = s[i];
            
            if(visited[c - 'a']) continue;
            
            while(!st.empty() &&
                  st.back() > c &&
                  lastOccurrence[st.back() - 'a'] > i){
                
                visited[st.back() - 'a'] = false;
                st.pop_back();
            }
            
            st.push_back(c);
            visited[c - 'a'] = true;
        }
        
        return st;
    }
};
