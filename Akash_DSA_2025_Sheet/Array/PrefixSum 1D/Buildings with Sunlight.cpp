class Solution {
  public:
    int visibleBuildings(vector<int>& arr) {
        // code here
        int n=arr.size();
        int count=1;
        int prev=arr[0];
        for(int i=1;i<n;i++){
            if(prev<=arr[i]){
                prev=arr[i];
                count++;
            }
        }
        return count;
    }
};
