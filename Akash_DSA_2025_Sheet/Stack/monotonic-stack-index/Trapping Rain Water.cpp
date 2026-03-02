
// ✅ 1️⃣ Prefix Max & Suffix Max (Extra Space O(n))
// 👉 Precompute left max and right max arrays.

class Solution {
public:
    vector<int> buildLeftMax(vector<int>& height, int n) {
        vector<int> leftMax(n);
        leftMax[0] = height[0];
        for(int i = 1; i < n; i++) {
            leftMax[i] = max(leftMax[i - 1], height[i]);
        }
        return leftMax;
    }

    vector<int> buildRightMax(vector<int>& height, int n) {
        vector<int> rightMax(n);
        rightMax[n - 1] = height[n - 1];
        for(int i = n - 2; i >= 0; i--) {
            rightMax[i] = max(rightMax[i + 1], height[i]);
        }
        return rightMax;
    }
    int maxWater(vector<int>& arr) {
        int n = arr.size();
        if(n == 0) return 0;
        vector<int> leftMax = buildLeftMax(arr, n);
        vector<int> rightMax = buildRightMax(arr, n);
        int water = 0;
        for(int i = 0; i < n; i++) {
            water += min(leftMax[i], rightMax[i]) - arr[i];
        }
        return water;
    }
};

// ✔ Time: O(n)
// ✔ Space: O(n)


// ✅ 2️⃣ Using Global Maximum Index (Better Space O(1))
// 👉 First find highest bar index
// 👉 Process left side and right side separately

class Solution {
public:
    int maxWater(vector<int>& arr) {
        int n = arr.size();
        if(n == 0) return 0;
        // Find index of maximum element
        int maxIdx = 0;
        for(int i = 1; i < n; i++) {
            if(arr[i] > arr[maxIdx]) {
                maxIdx = i;
            }
        }
        int water = 0;
        // Left side
        int leftMax = 0;
        for(int i = 0; i < maxIdx; i++) {
            leftMax = max(leftMax, arr[i]);
            water += leftMax - arr[i];
        }
        // Right side
        int rightMax = 0;
        for(int i = n - 1; i > maxIdx; i--) {
            rightMax = max(rightMax, arr[i]);
            water += rightMax - arr[i];
        }
        return water;
    }
};

// ✔ Time: O(n)
// ✔ Space: O(1)

// ✅ 3️⃣ Cleaner Two-Side Approach (Same Idea More Structured)

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n == 0) return 0;
        // Find highest bar index
        int maxIdx = 0;
        for(int i = 1; i < n; i++) {
            if(height[i] > height[maxIdx]) {
                maxIdx = i;
            }
        }
        int water = 0;
        // Process left side
        int leftMax = 0;
        for(int i = 0; i < maxIdx; i++) {
            leftMax = max(leftMax, height[i]);
            water += leftMax - height[i];
        }
        // Process right side
        int rightMax = 0;
        for(int i = n - 1; i > maxIdx; i--) {
            rightMax = max(rightMax, height[i]);
            water += rightMax - height[i];
        }
        return water;
    }
};

// ✔ Time: O(n)
// ✔ Space: O(1)


// ✅ 4️⃣ Stack Based Solution (Monotonic Stack)
// 👉 Use stack to store indices
// 👉 When we find a bar higher than stack top → water can be trapped

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int water = 0;
        stack<int> st;   // stores indices
        for(int i = 0; i < n; i++) {
            // While current height is greater than height at stack top
            while(!st.empty() && height[i] > height[st.top()]) {
                int mid = st.top();   // bottom element
                st.pop();
                if(st.empty()) break;
                int left = st.top();
                int width = i - left - 1;
                int boundedHeight = min(height[i], height[left]) - height[mid];
                water += width * boundedHeight;
            }
            st.push(i);
        }
        return water;
    }
};