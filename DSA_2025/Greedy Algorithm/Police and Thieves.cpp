class Solution {
  public:
    int catchThieves(vector<char> &arr, int k) {
        // Code here
        int n=arr.size();
        int police=0,thief=0;
        int count=0;
        while(police<n && arr[police]!='P')police++;// moves to next 'P'
        while(thief<n && arr[thief]!='T')thief++;// moves to next 'T'
        // police → should always point to a 'P'
        // thief → should always point to a 'T'
        while(police<n && thief<n){
            if(abs(police-thief)<=k){
                count++;
                police++;
                thief++;
            }
            else if(police<thief)police++;
            else if(thief<police)thief++;
            while(police<n && arr[police]!='P')police++;// moves to next 'P'
            while(thief<n && arr[thief]!='T')thief++;// moves to next 'T'
        }
        return count;
    }
};