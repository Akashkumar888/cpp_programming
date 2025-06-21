



class Solution {
  public:
    int catchThieves(vector<char> &arr, int k) {
        int n = arr.size();
        // Store indices of police and thieves
        vector<int> police_positions;
        vector<int> thief_positions;
        // Fill positions
        for (int i = 0; i < n; i++) {
            if (arr[i] == 'P')
                police_positions.push_back(i);
            else if (arr[i] == 'T')
                thief_positions.push_back(i);
        }
        // Use two pointers to match police and thieves
        int i = 0, j = 0;
        int m= police_positions.size();
        int l=thief_positions.size();
        int count = 0;
        while(i<m && j<l){
            int police = police_positions[i];
            int thief = thief_positions[j];
            if(abs(police-thief)<=k){
                count++;
                i++;
                j++;
            } 
            else if (thief < police) {
                j++;
            }
            else if(police<thief) {
                i++;
            }
        }
        return count;
    }
};



class Solution {
  public:
    int catchThieves(vector<char> &arr, int k) {
        // Code here
        int n=arr.size();
        int police=0,thief=0;
        while(police<n&& arr[police]!='P')police++;
        while(thief<n && arr[thief]!='T')thief++;
        int count=0;
        while(police<n && thief<n){
            if(abs(police-thief)<=k){
                count++;
           thief++;
           police++;
            }
           else if(thief<n && thief<police)thief++;
           else if(police<n && police<thief)police++;
        while(police<n&& arr[police]!='P')police++;
        while(thief<n && arr[thief]!='T')thief++;
        }
        return count;
    }
};

