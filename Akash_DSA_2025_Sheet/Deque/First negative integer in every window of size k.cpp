// 3️⃣ Condition variants
// dq.front() <= i-k
// // vs
// i - dq.front() >= k

// ✔ Both are 100% equivalent
// ✔ Both correctly remove out-of-window indices


class Solution {
  public:
    vector<int> firstNegInt(vector<int>& arr, int k) {
        // write code here
        // sliding window ko slide krna hai one by one 
        // deque pop_front for left index
        // deque push_back for right index
        int n=arr.size();
        vector<int>result(n-k+1);//window
        deque<int>dq;
        for(int i=0;i<n;i++){
            // Step 1 // Step 1: remove out-of-window indices
            while(!dq.empty() && dq.front() <= i-k )dq.pop_front();
            // Step 2 // Step 2: add current index if negative
            if(arr[i]<0)dq.push_back(i);
             // Step 3: Store answer when window is ready
            if (i - k + 1 >= 0) {
                result[i-k+1]=(dq.empty() ? 0 : arr[dq.front()]);
            }
        }
        return result;
    }
};

class Solution {
  public:
    vector<int> firstNegInt(vector<int>& arr, int k) {
        // write code here
        // sliding window ko slide krna hai one by one 
        // deque pop_front for left index
        // deque push_back for right index
        int n=arr.size();
        vector<int>result;//window
        deque<int>dq;
        for(int i=0;i<n;i++){
            // Step 1 // Step 1: remove out-of-window indices
            while(!dq.empty() && i - dq.front() >= k )dq.pop_front();
            // Step 2 // Step 2: add current index if negative
            if(arr[i]<0)dq.push_back(i);
             // Step 3: Store answer when window is ready
            if (i - k + 1 >= 0) {
                result.push_back((dq.empty() ? 0 : arr[dq.front()]));
            }
        }
        return result;
    }
};


class Solution {
  public:
    vector<int> firstNegInt(vector<int>& arr, int k) {
        // write code here
        // sliding window ko slide krna hai one by one 
        // deque pop_front for left index
        // deque push_back for right index
        int n=arr.size();
        vector<int>result;//window
        deque<int>dq;
        for(int i=0;i<n;i++){
            // Step 1 // Step 1: remove out-of-window indices
            while(!dq.empty() && dq.front() <= i-k )dq.pop_front();
            // Step 2 // Step 2: add current index if negative
            if(arr[i]<0)dq.push_back(i);
             // Step 3: Store answer when window is ready
            if (i - k + 1 >= 0) {
                result.push_back((dq.empty() ? 0 : arr[dq.front()]));
            }
        }
        return result;
    }
};


class Solution {
  public:
    vector<int> firstNegInt(vector<int>& arr, int k) {
        int n = arr.size();
        deque<int> dq;        // stores indices of negative numbers
        vector<int> result;
        // 🔹 Process first window of size k
        for (int i = 0; i < k; i++) {
            if (arr[i] < 0)dq.push_back(i);
        }
        // 🔹 Store answer for first window
        if (!dq.empty())result.push_back(arr[dq.front()]);
        else result.push_back(0);

        // 🔹 Process remaining windows
        for (int i = k; i < n; i++) {

            // remove indices which are out of current window
            if (!dq.empty() && i - dq.front() >= k)dq.pop_front();
            

            // add current element if it is negative
            if (arr[i] < 0) dq.push_back(i);

            // store answer for current window
            if (!dq.empty())result.push_back(arr[dq.front()]);
            else result.push_back(0);
        }
        return result;
    }
};



class Solution {
  public:
    vector<int> FirstNegativeInteger(vector<int>& arr, int k) {
        // write code here
        int n=arr.size();
        vector<int>ans;
        deque<int>dq;
        int i=0,j=0;
        while(j<n){
            if(arr[j]<0)dq.push_back(arr[j]);
            while(j-i+1>k){
                if(arr[i]<0 && !dq.empty())dq.pop_front();
                i++;
            }
            if(j-i+1==k){
                if(dq.empty())ans.push_back(0);
                else ans.push_back(dq.front());
            }
            j++;
        }
    return ans;    
    }
};

