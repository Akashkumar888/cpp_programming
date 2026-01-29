
class Solution {
  public:
  string st;//string acts as stack
  string last;
    void append(char x) {
        // append x into document
        st.push_back(x);
    }

    void undo() {
        // undo last change
        if(st.empty())return;
        last.push_back(st.back());
        st.pop_back();
    }

    void redo() {
        // redo changes
        if(last.empty()) return;   // ✅ check redo stack
        st.push_back(last.back());
        last.pop_back();
    }

    string read() {
        // read the document
        return st;
    }
};