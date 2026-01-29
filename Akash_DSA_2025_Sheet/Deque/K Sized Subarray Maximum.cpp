

class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        // code here
        int n=arr.size();
        vector<int>ans;
        deque<int>dq;
        for(int i=0;i<n;i++){
           while(!dq.empty() && dq.front()<=i-k) dq.pop_front(); // window shrink karo
           while(!dq.empty() && arr[i]> arr[dq.back()]) dq.pop_back(); // monotonic order me otherwise pop kr do 
           dq.push_back(i);
           if(i>=k-1){
               ans.push_back(arr[dq.front()]);
           }
        }
        return ans;
    }
};



class Solution {
  public:
//   Insert here  ←  [  ... elements ...  ]  →  Insert here
// Delete here  ←                          →  Delete here
//       Front                                Back

// Using Deque for Max / Min (Monotonic Deque)
// In many problems (like sliding window maximum/minimum), we use a deque in a special way:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        vector<int> result;
        deque<int> dq; // store indices
// For Maximum (Decreasing Deque)
// Keep elements in decreasing order
// Front always holds the maximum
        // deque<int>minDq;
// For Minimum (Increasing Deque)
// Keep elements in increasing order
// Front always holds the minimum

// Correct Approach
// We must store indices in the deque, not values.
// Then we can:
// Remove elements from back that are smaller than current.
// Remove elements from front that are out of window (i - k).
// The front always holds the index of the maximum.
        for(int i=0;i<n;i++){
            // Step 1: Remove out-of-window elements
            if (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }

            // Step 2: Maintain decreasing order
            while (!dq.empty() && arr[dq.back()] < arr[i]) {
                dq.pop_back();
            }

            dq.push_back(i);
            // Step 3: Store answer when window is ready
            // window size j-i+1 like that i-k+1>=0
            if(i-k+1>=0)result.push_back(arr[dq.front()]);
        }
        return result;
    }
};

// 1️⃣ Using multiset — O(n log k)
vector<int> maxOfSubarrays_Multiset(vector<int>& arr, int k) {
    int n = arr.size();
    vector<int> res;
    multiset<int> ms;

    for (int i = 0; i < n; i++) {
        ms.insert(arr[i]);

        if (i >= k) {
            ms.erase(ms.find(arr[i - k])); // remove outgoing element
        }

        if (i >= k - 1) {
            res.push_back(*ms.rbegin()); // max element
        }
    }
    return res;
}


// Time: O(n log k)
// Space: O(k)

// 2️⃣ Using Max Heap — O(n log n)
vector<int> maxOfSubarrays_Heap(vector<int>& arr, int k) {
    int n = arr.size();
    vector<int> res;
    priority_queue<pair<int,int>> pq; // {value, index}

    for (int i = 0; i < n; i++) {
        pq.push({arr[i], i});

        // remove out-of-window elements
        while (!pq.empty() && pq.top().second <= i - k) {
            pq.pop();
        }

        if (i >= k - 1) {
            res.push_back(pq.top().first);
        }
    }
    return res;
}


// Time: O(n log n)
// Space: O(n)

// 3️⃣ Block Decomposition (Prefix–Suffix) — O(n) but O(n) space
vector<int> maxOfSubarrays_Block(vector<int>& arr, int k) {
    int n = arr.size();
    vector<int> left(n), right(n), res;

    for (int i = 0; i < n; i++) {
        if (i % k == 0) left[i] = arr[i];
        else left[i] = max(left[i - 1], arr[i]);
    }

    for (int i = n - 1; i >= 0; i--) {
        if (i == n - 1 || (i + 1) % k == 0) right[i] = arr[i];
        else right[i] = max(right[i + 1], arr[i]);
    }

    for (int i = 0; i <= n - k; i++) {
        res.push_back(max(right[i], left[i + k - 1]));
    }

    return res;
}


// Time: O(n)
// Space: O(n) ❌ (violates O(k))

class Solution {
  public:
//   Insert here  ←  [  ... elements ...  ]  →  Insert here
// Delete here  ←                          →  Delete here
//       Front                                Back

// Using Deque for Max / Min (Monotonic Deque)
// In many problems (like sliding window maximum/minimum), we use a deque in a special way:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        // code here
        int n=arr.size();
        vector<int>result;
        deque<int>maxDq;
// For Maximum (Decreasing Deque)
// Keep elements in decreasing order
// Front always holds the maximum
        deque<int>minDq;
// For Minimum (Increasing Deque)
// Keep elements in increasing order
// Front always holds the minimum
        for(int i=0;i<n;i++){
            // step 1
            while(!minDq.empty() && minDq.back()>arr[i]){
                minDq.pop_back();
            }
            minDq.push_back(arr[i]);
            // step 2
            while(!maxDq.empty() && maxDq.back()<arr[i]){
                maxDq.pop_back();
            }
            maxDq.push_back(arr[i]);
            // step 3
            if(i-k+1>=0)result.push_back(maxDq.front());
        }
        return result;
    }
};

