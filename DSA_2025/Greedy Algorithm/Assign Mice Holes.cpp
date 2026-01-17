
// Proof idea (Greedy correctness):
// Suppose you try to "cross pair" (like mouse1 with hole3, mouse3 with hole1). That would increase the maximum distance, because sorted order ensures each pair is "locally optimal".
// (This is similar to minimizing maximum difference problems → always align sorted arrays.)
// Why take maxi of all distances?
// Each mouse has its own travel distance abs(mices[i]-holes[i]).
// The total time is determined by the slowest mouse (the one who travels the farthest).
// Hence, we compute maxi.

class Solution {
  public:
    int assignHole(vector<int>& mices, vector<int>& holes) {
        // code here
        int n=mices.size();
        int maxi=INT_MIN;
        sort(mices.begin(),mices.end());
        sort(holes.begin(),holes.end());
        int i=0;
        while(i<n){
            maxi=max(maxi,abs(mices[i]-holes[i]));
            i++;
        }
        return maxi;
    }
};

// ✅ Time Complexity
// Sorting → O(n log n)
// Loop → O(n)
// Total: O(n log n)
