class Solution {
  public:
// Each subsequence consists of consecutive integers 
//(each number is exactly one greater than the previous).
// Every subsequence has a length of at least k.
    bool isPossible(vector<int>& arr, int k) {
        // code here
        typedef pair<int,int>P;
        int n=arr.size();
        auto cmp=[&](const P&p1,const P&p2){
        // smaller length has higher priority
            if(p1.first == p2.first)return p1.second > p2.second; 
            // smaller number has higher priority
            return p1.first > p2.first;  
        };
        // Min-heap stores pairs:
    //{number, length of subsequence ending with this number}
        priority_queue<P,vector<P>,decltype(cmp)>pq(cmp);
        int i = 0;
        while(i < n) {
            if(pq.empty()) {
                // If heap is empty, start a new subsequence
                pq.push({arr[i], 1});
                i++;
            }
            else {
                auto top = pq.top();
                if(arr[i] == top.first) {
                    // If current number same as top, 
                    //start a new subsequence
                    pq.push({arr[i], 1});
                    i++;
                }
                else if(arr[i] == top.first + 1) {// top.first + 1 because min heap at top min element
                    // If current number is consecutive, 
                    //extend the subsequence
                    // extend shortest subsequence ending with previous number
                    pq.pop();
                    pq.push({arr[i], top.second + 1}); // use current number
                    i++;
                }
                else {
                    // If current number is not 
                    //consecutive, check if the top subsequence is valid
                    if(top.second < k) return false;
                    pq.pop();
                }
            }
        }
        // After processing all numbers, 
        //ensure all subsequences have length >= k
        while(!pq.empty()) {
            if(pq.top().second < k) return false;
            pq.pop();
        }
        return true;
    }
};
