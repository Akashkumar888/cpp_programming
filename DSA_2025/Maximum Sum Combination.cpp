
class Solution {
  public:
    vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
        // code here
        int n=a.size();
        if(n==1)return {a[0]+b[0]};
        vector<int>ans;
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=n-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                pq.push(a[i]+b[j]);
                if(pq.size()>k)pq.pop();
            }
        }
        while(!pq.empty()){
            ans.push_back(pq.top());
            pq.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

// 🔸 Time Complexity:
// Outer loop: O(n)
// Inner loop: O(n)
// Each pq.push and pq.pop: O(log k)
// Total iterations: O(n²)
// 👉 So, overall time = O(n² × log k)

// 🔸 Space Complexity:
// Min-heap of size at most k ⇒ O(k)
// Answer vector: O(k)
// 🔹 Total space = O(k)





class Solution {
  public:
    vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
        // code here
        int n=a.size();// both are same size array
        priority_queue<int,vector<int>,greater<int>>pq;
        sort(a.begin(),a.end(),greater<int>());
        sort(b.begin(),b.end(),greater<int>());
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int sum=b[j]+a[i];
                if(pq.size()<k)pq.push(sum);
                else if(sum>pq.top()){
                    pq.pop();
                    pq.push(sum);
                }
                else break;
            }
        }
        // vector<int>ans;
        // while(!pq.empty()){
        //     ans.push_back(pq.top());
        //     pq.pop();
        // }
        // reverse(ans.begin(),ans.end());
        vector<int>ans(k);
        int idx=k-1;
        while(!pq.empty() && idx>=0){
            ans[idx]=(pq.top());
            pq.pop();
            idx--;
        }
        return  ans;
    }
};


// 🔸 Time Complexity:
// Worst case: O(n² × log k) — same as brute force
// Best/average case: Improved in practice due to early break when sum is no longer greater
// 👉 Still O(n² × log k) in the worst case, but faster in practice due to pruning.

// 🔸 Space Complexity:
// Heap: O(k)
// Answer vector: O(k)
// 🔹 Total space = O(k)




class Solution {
  public:
    vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
        int n = a.size();
        sort(a.begin(), a.end(), greater<int>());
        sort(b.begin(), b.end(), greater<int>());
        typedef pair<int, pair<int, int>> P;
        priority_queue<P> pq;
        set<pair<int, int>> visited;
        pq.push({a[0] + b[0], {0, 0}});
        visited.insert({0, 0});
        vector<int> ans;
        while (ans.size() < k && !pq.empty()) {
            auto top = pq.top(); pq.pop();
            int sum = top.first;
            int i = top.second.first;
            int j = top.second.second;
            ans.push_back(sum);
            if (i + 1 < n && visited.count({i + 1, j}) == 0) {
                pq.push({a[i + 1] + b[j], {i + 1, j}});
                visited.insert({i + 1, j});
            }
            if (j + 1 < n && visited.count({i, j + 1}) == 0) {
                pq.push({a[i] + b[j + 1], {i, j + 1}});
                visited.insert({i, j + 1});
            }
        }
        return ans;
    }
};

// 📌 Total Time Complexity: O(n log n) + O(k log k)

// Space Complexity	O(k)

