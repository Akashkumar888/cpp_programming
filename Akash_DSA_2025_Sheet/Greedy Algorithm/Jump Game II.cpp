
// ✅ **This method is called:
// 👉 “Greedy – Level-based BFS on Array”
// 👉 or simply “Greedy BFS Layer Expansion”**

// 🔍 Why is it called Greedy + BFS-like?
// ✔ You treat ranges [l, r] as levels of a BFS tree

// l and r represent the current window (current level of jumps)
// Inside that window you find the farthest point reachable, like exploring all nodes at one BFS level

// ✔ You expand to next level by:
// l = r + 1        // start of next window
// r = maxJump      // end of next window
// This is similar to how BFS explores layer by layer.

class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        int jump=0;
        int l=0,r=0;
        while(r<n-1){// beacuse It's guaranteed that you can reach nums[n - 1].
         int maxJump=0;
         for(int j=l;j<=r;j++){
            maxJump=max(maxJump,j+nums[j]);
         }
         l=r+1;
         r=maxJump;
         jump++;
        }
        return jump;
    }
};
