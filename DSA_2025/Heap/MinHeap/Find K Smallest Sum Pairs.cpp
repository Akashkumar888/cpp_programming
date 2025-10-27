
class Solution {
  public:
  //Given two integer arrays arr1[] and arr2[] sorted in ascending order 
  //and an integer k, your task is to find k pairs with the smallest sums,
  //such that one element of each pair belongs to arr1[] and the other belongs to arr2[].
  //Return the list of these k pairs, where each pair is represented as [arr1[i], arr2[j]].
    vector<vector<int>> kSmallestPair(vector<int> &arr1, vector<int> &arr2, int k) {
        // code here
        vector<vector<int>>result;
        typedef pair<int,pair<int,int>>P;
        int n=arr1.size();
        priority_queue<P>pq;
        for(int i=0;i<arr1.size();i++){
            for(int j=0;j<arr2.size();j++){
                pq.push({arr1[i]+arr2[j],{arr1[i],arr2[j]}});
                if(pq.size()>k)pq.pop();
            }
        }
        while(!pq.empty()){
            auto p=pq.top().second;
            result.push_back({p.first,p.second});
            pq.pop();
        }
        reverse(result.begin(),result.end());
        return result;
    }
};



class Solution {
  public:
  //Given two integer arrays arr1[] and arr2[] sorted in ascending order 
  //and an integer k, your task is to find k pairs with the smallest sums,
  //such that one element of each pair belongs to arr1[] and the other belongs to arr2[].
  //Return the list of these k pairs, where each pair is represented as [arr1[i], arr2[j]].
    vector<vector<int>> kSmallestPair(vector<int> &arr1, vector<int> &arr2, int k) {
        // code here
        vector<vector<int>>result;
        typedef pair<int,pair<int,int>>P;
        int n = arr1.size();
        int m = arr2.size();
        // min-heap: {sum, {i, j}}
        priority_queue<P, vector<P>, greater<P>> pq;
        
        // Push pairs (arr1[i], arr2[0]) for first min(n, k) elements
        for (int i = 0; i < min(n,k); i++) {
            pq.push({arr1[i] + arr2[0], {i, 0}});
        }

        // Extract k smallest pairs
        while (k-- && !pq.empty()) {
            auto cur = pq.top().second;
            pq.pop();
            int i = cur.first;
            int j = cur.second;
            result.push_back({arr1[i],arr2[j]});
            // Push next pair in same row (arr1[i], arr2[j+1])
            if (j + 1 < m) {
                pq.push({arr1[i] + arr2[j + 1], {i, j + 1}});
            }
        }
        return result;
    }
};