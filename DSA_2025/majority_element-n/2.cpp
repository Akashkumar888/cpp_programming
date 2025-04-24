
class Solution {
  public:
    int majorityElement(vector<int>& arr) {
        // code here
        int n=arr.size();
        int freq=1;
        int maj=arr[0];
        for(int i=1;i<n;i++){
            if(maj==arr[i])freq++;
            else if(freq==0){
                maj=arr[i];
                freq=1;
            }
            else{
                freq--;
            }
        }
        freq=0;
        for(int i=0;i<n;i++)if(maj==arr[i])freq++;
        if(freq>floor(n/2))return maj;
        return -1;
    }
  };