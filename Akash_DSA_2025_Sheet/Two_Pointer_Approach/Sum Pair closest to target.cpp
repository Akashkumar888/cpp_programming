
class Solution {
  public:
    vector<int> sumClosest(vector<int>& arr, int target) {
        // code here
        sort(arr.begin(),arr.end());
        int n=arr.size();
        int i=0,j=n-1;
        int minDiff=INT_MAX;
        int maxAbsDiff=INT_MIN;
        int first=-1,second=-1;
        while(i<j){
            int sum=(arr[i]+arr[j]);
            int Diff=(arr[j]-arr[i]);
            if(abs(target-sum)<minDiff || (abs(target-sum)==minDiff && Diff>maxAbsDiff)){
                minDiff=abs(target-sum);
                first=arr[i];
                second=arr[j];
                maxAbsDiff=Diff;
            }
            if(sum<target)i++;
            else if(sum>=target) j--;
        }
        if(first==-1 && second==-1)return {};
        return {first,second};
    }
};

