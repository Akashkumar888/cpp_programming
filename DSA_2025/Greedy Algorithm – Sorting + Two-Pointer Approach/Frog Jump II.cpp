
// ✔ 1. You must visit each stone at most once.
// So the frog cannot jump backwards to “fix” a large gap.

// ✔ 2. To minimize the maximum jump, you want evenly distributed jumps.
// Skipping every alternate stone creates the most balanced jumps along the path.

// ✔ 3. Visiting in sequence (0 → 1 → 2 → 3 ...) sometimes forces huge jumps.
// Skips allow distributing the difference more evenly.

// ✔ 4. The worst jump occurs between stones 2 apart.
// That’s exactly what your loop checks.

class Solution {
public:
// strictly increasing order representing the positions of stones in a river.
// it can jump to any stone at most once.
// is jumping to stones[j], the length of the jump is |stones[i] - stones[j]|
    int maxJump(vector<int>& stones) {
        int n=stones.size();
        if(n<=1)return -1;
        if(n==2)return stones[1]-stones[0];
        int alternativeJump=0;
        for(int i=0;i<n-2;i++){
          alternativeJump=max(alternativeJump,stones[i+2]-stones[i]);
        }
        return alternativeJump;
    }
};
