class Solution {
  public:
    void segregate0and1(vector<int> &arr) {
        // code here
        int n=arr.size();
        int i=0,j=0;
        while(i<n){
            if(arr[i]==0){
                arr[j]=0;
                j++;
            }
            i++;
        }
        while(j<n){
            arr[j]=1;
            j++;
        }
    }
};
