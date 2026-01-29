
class Solution {
  public:
//where each element is at most k positions away from its correct position in the sorted order.
// Your task is to restore the sorted order of arr[] by rearranging the elements in place.
    void nearlySorted(vector<int>& arr, int k) {
        // code here
        int n=arr.size();
        vector<int>result=arr;
        sort(result.begin(),result.end());
        map<int,int>mp1,mp2;
        for(int i=0;i<n;i++){
            mp1[result[i]]=i;
            mp2[arr[i]]=i;
        }
        for(int i=0;i<n;i++){
            int idx1=mp1[arr[i]];
            int second=result[i];
            int idx2=mp2[second];
            if(arr[i]==result[i])continue;
            else if(abs(idx1-i)<=k){
                swap(arr[i],arr[idx2]);
                mp2[arr[i]]=i;
                mp2[arr[idx2]]=idx2;
            }
            else continue;
        }
    }
};

class Solution {
  public:
//where each element is at most k positions away from its correct position in the sorted order.
// Your task is to restore the sorted order of arr[] by rearranging the elements in place.
    void nearlySorted(vector<int>& arr, int k) {
        // code here
        // k position left me ya right me hoga 
        // at most k postion and min element pahle in sorting me
        // that's why we use min-Heap
        int n=arr.size();
        priority_queue<int,vector<int>,greater<int>>pq; // min heap
        int j=0;
        for(int i=0;i<n;i++){
            pq.push(arr[i]);
            if(pq.size()>k){
                arr[j]=pq.top();
                pq.pop();
                j++;
            }
        }
        while(!pq.empty()){
            arr[j]=pq.top();
            pq.pop();
            j++;
        }
    }
};