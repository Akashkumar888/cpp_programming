#include <stack>
#include <climits>

class MinStack {
    std::stack<long long> st;
    long long mini;

public:
    MinStack() {
        mini = LLONG_MAX;
    }

    void push(int x) {
        long long newval = (long long)x;
        if (st.empty()) {
            mini = newval;
            st.push(newval);
        } else {
            if (newval >= mini) {
                st.push(newval);
            } else {
                st.push(2 * newval - mini); // Encoded value to track the previous min
                mini = newval;
            }
        }
    }

    void pop() {
        if (st.empty()) return;
        long long ele = st.top();
        st.pop();
        if (ele < mini) {
            mini = 2 * mini - ele; // Restore previous min
        }
    }

    int peek() {
        if (st.empty()) return -1;
        long long topval = st.top();
        return (topval < mini) ? mini : topval;
    }

    int getMin() {
        if (st.empty()) return -1;
        return mini;
    }
};
