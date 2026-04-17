class Solution {
  public:
    int countIncreasing(vector<int>& arr) {
        // code here.
        int n=arr.size();
        int count=0;
        int i=0,j=1;
        while(j<n){
            int prevIdx=j-1;
            if( arr[prevIdx]<arr[j]){
                count+=(prevIdx-i+1);
            }
            else {
                i=j;
            }
            j++;
        }
        return count;
    }
};

class Solution {
  public:
    int countIncreasing(vector<int>& arr) {
        int n=arr.size();
        int len=1;  // current increasing streak
        int count=0;
        for(int i=1;i<n;i++){
            if(arr[i-1] < arr[i]){
                len++;
            } 
            else{
                count +=(len*(len-1))/2;
                len = 1;
            }
        }
        // add last segment
        count +=(len*(len-1))/2;
        return count;
    }
};
