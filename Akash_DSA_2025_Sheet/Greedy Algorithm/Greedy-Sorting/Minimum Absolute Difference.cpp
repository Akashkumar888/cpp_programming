
class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int n=arr.size();
        int k=INT_MAX;
        for(int i=0;i<n-1;i++)k=min(k,arr[i+1]-arr[i]);
        vector<vector<int>>result;
        for(int i=0;i<n-1;i++){
          if(arr[i+1]-arr[i]==k){
          result.push_back({arr[i],arr[i+1]});
          }
        }
        return result;
    }
};



class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        vector<vector<int>> result;
        int k = INT_MAX;

        for(int i = 0; i < arr.size() - 1; i++){
            int diff = arr[i+1] - arr[i];
            if(diff < k){
                k = diff;
                result.clear();                 // new smaller diff found
                result.push_back({arr[i], arr[i+1]});
            } 
            else if(diff == k){
                result.push_back({arr[i], arr[i+1]});
            }
        }
        return result;
    }
};

