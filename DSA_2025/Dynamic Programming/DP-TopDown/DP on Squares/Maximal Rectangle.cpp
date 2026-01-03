
class Solution {
public:
    // Largest Rectangle in Histogram
    int largestRectangleArea(const vector<int>& heights) {
        vector<int> h = heights;   // local copy
        h.push_back(0);            // sentinel
        stack<int> st;
        int maxArea = 0;
        for (int i = 0; i < h.size(); i++) {
            while (!st.empty() && h[i] < h[st.top()]) {
                int height = h[st.top()];
                st.pop();
                int width = st.empty() ? i : i - st.top() - 1;
                maxArea = max(maxArea, height * width);
            }
            st.push(i);
        }
        return maxArea;
    }
    // Maximal Rectangle in Binary Matrix
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<int> height(cols, 0);
        int maxArea = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == '1')height[j]++;
                else height[j] = 0;
            }
            maxArea = max(maxArea, largestRectangleArea(height));
        }
        return maxArea;
    }
};



class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;

        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> height(n, 0);
        vector<int> left(n, 0);
        vector<int> right(n, n);

        int maxArea = 0;

        for (int i = 0; i < m; i++) {

            // 🔹 Step 1: Update height
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1')
                    height[j]++;
                else
                    height[j] = 0;
            }

            // 🔹 Step 2: Update left boundaries
            int curLeft = 0;
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1')
                    left[j] = max(left[j], curLeft);
                else {
                    left[j] = 0;
                    curLeft = j + 1;
                }
            }

            // 🔹 Step 3: Update right boundaries
            int curRight = n;
            for (int j = n - 1; j >= 0; j--) {
                if (matrix[i][j] == '1')
                    right[j] = min(right[j], curRight);
                else {
                    right[j] = n;
                    curRight = j;
                }
            }

            // 🔹 Step 4: Calculate area
            for (int j = 0; j < n; j++) {
                int area = height[j] * (right[j] - left[j]);
                maxArea = max(maxArea, area);
            }
        }

        return maxArea;
    }
};
