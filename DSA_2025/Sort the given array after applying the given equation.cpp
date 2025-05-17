
class Solution {
  public:
    vector<int> sortArray(vector<int> &arr, int A, int B, int C) {
        // code here
        vector<int>ans;
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int &num:arr){
            int val=A*num*num+B*num+C;
            pq.push(val);
        }
        while(!pq.empty()){
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;
    }
  };



 class Solution {
  public:
    vector<int> sortArray(vector<int> &arr, int A, int B, int C) {
        // code here
        vector<int>ans;
        for(int &num:arr){
            int val=A*num*num+B*num+C;
            ans.push_back(val);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
  };
  
  

  class Solution {
  public:
    vector<int> sortArray(vector<int> &arr, int A, int B, int C) {
        // code here
    int n = arr.size();
    vector<int> result(n);
    int i = 0, j = n - 1;
    int index = (A >= 0) ? n - 1 : 0;
    auto lambda = [&](int x) {
        return A * x * x + B * x + C;
    };
    
    while (i <= j) {
        int val_i = lambda(arr[i]);
        int val_j = lambda(arr[j]);
        if (A >= 0) {
            // Put larger values at the end
            if (val_i > val_j) {
                result[index--] = val_i;
                i++;
            } else {
                result[index--] = val_j;
                j--;
            }
        } else {
            // Put smaller values at the start
            if (val_i < val_j) {
                result[index++] = val_i;
                i++;
            } else {
                result[index++] = val_j;
                j--;
            }
        }
    }
    return result;
    }
  };

  