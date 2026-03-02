
class Solution {
  public:
    void pushZerosToEnd(vector<int>& arr) {
        // code here
        int n=arr.size();
        int i=0,j=0;
        while(j<n){
            if(arr[j]!=0){
                arr[i]=arr[j];
                i++;
            }
            j++;
        }
        while(i<n){
            arr[i]=0;
            i++;
        }
    }
};