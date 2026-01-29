
class Solution {
  public:
    int minSoldiers(vector<int>& arr, int k) {
        // code here
        int n=arr.size();
        priority_queue<int>pq;
        int count=0;
        for(int &num:arr){
        if(num%k==0)count++;
        else pq.push(k-(num%k));
        if(pq.size()>((n % 2) ? (n / 2) + 1 : (n / 2)) - count)pq.pop();
        }
        if(count>((n % 2) ? (n / 2) + 1 : (n / 2)))return 0;
        int sum=0;
        while(!pq.empty()){
            sum+=pq.top();
            pq.pop();
        }
        return sum;
    }
};

// ⏳ Time Complexity Analysis
// Loop over arr → O(n)
// Inside loop:num % k → O(1)
// pq.push(...) → O(log n) (max-heap insertion)
// pq.pop() (in worst case) → O(log n)
// So the loop part is:O(n log n) (since push/pop are logarithmic)
// Emptying the priority queue
// At most n pops → O(n log n)
// Total Time Complexity:
// O(n log n)
// Because both push and pop operations dominate.

// 💾 Space Complexity Analysis
// Priority queue can hold at most n elements → O(n)
// Few integers for counters → O(1)
// Total Space Complexity:O(n)

