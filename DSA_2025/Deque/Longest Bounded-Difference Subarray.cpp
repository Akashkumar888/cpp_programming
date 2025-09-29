
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
    int n=nums.size();
    int i=0,j=0;
    int maxlen=0;
    multiset<int>st;
    while(j<n){
       st.insert(nums[j]);
       while((*st.rbegin()-*st.begin())>limit){
       st.erase(st.find(nums[i]));
       i++;
       }
       maxlen=max(maxlen,j-i+1);
       j++;
    }
    return maxlen;
    }
};


class Solution {
  public:
    vector<int> longestSubarray(vector<int>& arr, int x) {
        // code here
        int n=arr.size();
        vector<int>ans;
        int i=0,j=0;
        int start = 0, end = -1;  // ✅ fixed initialization
        int maxlen=0;
        multiset<int>st;
        while(j<n){
           st.insert(arr[j]);
           while((*st.rbegin()-*st.begin())>x){
           st.erase(st.find(arr[i]));
           i++;
           }
           // update best answer here (after fixing window)
           if(j-i+1>maxlen || (j-i+1==maxlen && i<start)){
               start=i;
               end=j;
               maxlen=max(maxlen,j-i+1);
           }
           j++;
        }
        for(int k=start;k<=end;k++)ans.push_back(arr[k]);
        return ans;
    }
};


class Solution {
  public:
    vector<int> longestSubarray(vector<int>& arr, int x) {
        // code here
        // find the longest sub-array where the absolute
        //difference between any two elements is not greater than x.
        // element nhi index store ok
        int n=arr.size();
        vector<int>ans;
        int start = 0, end = -1;  // ✅ fixed initialization
        int maxlen=0;
        deque<int>minDeque;// store min element like increasing order
        deque<int>maxDeque;// store max element like decreasing order
        int i=0,j=0;
        while(j<n){
            // maintain increasing order in minDeque
            // enqueue operation
            while (!minDeque.empty() && arr[minDeque.back()] > arr[j]) {
                minDeque.pop_back();
            }
            minDeque.push_back(j);
            // maintain decreasing order in maxDeque
            while (!maxDeque.empty() && arr[maxDeque.back()] < arr[j]) {
                maxDeque.pop_back();
            }
            maxDeque.push_back(j);
            //dequeue start 
        // shrink window
            while(!minDeque.empty() && !maxDeque.empty() && (arr[maxDeque.front()]-arr[minDeque.front()])>x){
                if(i==minDeque.front())minDeque.pop_front();
                if(i==maxDeque.front())maxDeque.pop_front();
                i++;
            }
            // update best answer here (after fixing window)
            if ((j - i + 1) > maxlen || ((j - i + 1) == maxlen && i < start)) {
                start = i;
                end = j;
                maxlen = j - i + 1;
            }
            j++;
        }
        for(int k=start;k<=end;k++)ans.push_back(arr[k]);
        return ans;
    }
};
