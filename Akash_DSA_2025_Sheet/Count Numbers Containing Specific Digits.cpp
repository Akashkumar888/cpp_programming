
class Solution {
  public:
  bool binarySearch(int m,vector<int>&arr,int tr){
      int l=0,r=m-1;
      while(l<=r){
          int mid=l+(r-l)/2;
          if(arr[mid]==tr)return true;
          else if(arr[mid]<tr)l=mid+1;
          else r=mid-1;
      }
      return false;
  }
    int countValid(int n, vector<int>& arr) {
        // code here
        int m=arr.size();
        sort(arr.begin(),arr.end());
        int total=9*pow(10,n-1);
        // Build a set of forbidden digits
        vector<int> forbiddenDigits;
        for (int d = 0; d <= 9;d++) {
            if (!binarySearch(m,arr,d)) {
                forbiddenDigits.push_back(d);
            }
        }
        int forbiddenSize=forbiddenDigits.size();
    
        // Count how many forbidden digits can be at first place (excluding 0)
        int validFirstDigits=0;
        for (auto &d : forbiddenDigits) {
            if (d!=0) validFirstDigits++;
        }
        // If no forbidden digits or first digit can't be formed → zero invalids
        if (validFirstDigits == 0) return total;
        // Total numbers made using ONLY forbidden digits
        int bad = validFirstDigits * pow(forbiddenSize, n - 1);
        // Answer: total - bad
        return total - bad;
    }
};


// ⏱ Time & Space Complexity
// Time Complexity:
// sort(arr) = O(m log m)
// binarySearch for 10 digits = O(10 log m)
// ✅ Final = O(m log m)

// Space Complexity:
// Only a few variables and a vector of at most size 10 →
// ✅ Final = O(1) (constant auxiliary space)

