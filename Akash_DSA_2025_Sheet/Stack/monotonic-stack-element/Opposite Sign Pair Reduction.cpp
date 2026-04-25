class Solution {
  public:
// If their absolute values are different, remove both elements and 
//insert the one with the greater absolute value, preserving its sign.
// If their absolute values are equal, remove both elements 
//without inserting any new element.
    vector<int> reducePairs(vector<int>& arr) {
        int n = arr.size();
        vector<int> result;
        stack<int> st;
        if (n == 0) return result;
        st.push(arr[0]);  // start from 1, so push first element
        for (int i = 1; i < n; i++) {
            int curr = arr[i];
            bool removed = false;
            while (!st.empty() && st.top() * curr < 0) {
                int top = st.top();

                if (abs(top) == abs(curr)) {
                    st.pop();      // both removed
                    removed = true;
                    break;
                }
                else if (abs(top) > abs(curr)) {
                    removed = true; // current removed
                    break;
                }
                else {
                    st.pop(); // top removed → continue checking
                }
            }
            if (!removed) {
                st.push(curr);
            }
        }
        while (!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};


class Solution {
public:
    vector<int> reducePairs(vector<int>& arr) {
        int n = arr.size();
        vector<int> result;
        stack<pair<int,int>> st;

        if (n == 0) return result;

        st.push({arr[0], (arr[0] < 0 ? -1 : 1)});

        for (int i = 1; i < n; i++) {
            int curr = arr[i];
            int sign = (curr < 0 ? -1 : 1);
            bool removed = false;

            while (!st.empty() && st.top().second != sign) {
                int top = st.top().first;

                if (abs(top) == abs(curr)) {
                    st.pop();
                    removed = true;
                    break;
                }
                else if (abs(top) > abs(curr)) {
                    removed = true;
                    break;
                }
                else {
                    st.pop();
                }
            }

            if (!removed) {
                st.push({curr, sign});
            }
        }

        while (!st.empty()) {
            result.push_back(st.top().first);
            st.pop();
        }

        reverse(result.begin(), result.end());
        return result;
    }
};
