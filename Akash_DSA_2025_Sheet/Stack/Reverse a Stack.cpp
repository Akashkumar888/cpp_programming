
class Solution {
  public:
// To reverse a stack recursively, you need two recursive functions:

// 1️⃣ Remove top elements one by one
// 2️⃣ Insert an element at the bottom of stack
    // insert element at bottom of stack
    void insertAtBottom(stack<int> &st, int x) {
        if (st.empty()) {
            st.push(x);
            return;
        }
        int top = st.top();
        st.pop();
        insertAtBottom(st, x);// pahle sabse last me jao using recusrion se call pe call //first go till last
        st.push(top);
    }

    // reverse stack using recursion
    void reverseStack(stack<int> &st) {
        if (st.empty()) return;

        int x = st.top();
        st.pop();

        reverseStack(st); // pahle sabse last me jao using recusrion se call pe call        // pahle last tak jao
        insertAtBottom(st, x);   // fir bottom me daalo
    }
};
