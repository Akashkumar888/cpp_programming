// User function Template for C++
class Solution {
  public:
    int cost(vector<int>& arr) {
        // code here
        int n=arr.size();
        if(n<2) return 0;
        int mn=INT_MAX;
        for(int i=0;i<n;i++){
            if(arr[i]<mn) mn=arr[i];
        }
        return mn*(n-1);
    }
};

// User function Template for C++
class Solution {
  public:
    int cost(vector<int>& arr) {
        // code here
        int n=arr.size();
        if(n<2) return 0;
        sort(arr.begin(),arr.end());
        return arr[0]*(n-1);
    }
};
