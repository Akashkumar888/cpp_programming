
class Solution {
  public:
    int findMoves(vector<int>& chairs, vector<int>& passengers) {
        // code here
        int n=passengers.size();
        int count=0;
        sort(chairs.begin(),chairs.end());
        sort(passengers.begin(),passengers.end());
        for(int i=0;i<n;i++){
            count+=abs(passengers[i]-chairs[i]);
        }
        return count;
    }
};