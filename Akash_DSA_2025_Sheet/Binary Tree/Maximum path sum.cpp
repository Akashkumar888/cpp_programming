


// A path can start and end at any node, and it must be continuous (i.e., connected via parent-child edges).
// Recursively compute max path sums from left and right subtrees.
// l = best path sum from left child upward
// r = best path sum from right child upward

class Solution {
  public:
  int dfs(Node*root,int &maxSum){
      if(root==NULL)return 0;
      
      int l=dfs(root->left,maxSum);
      int r=dfs(root->right,maxSum);
      
      int niche_hi_milgaya_answer=l+r+root->data;
//       🟩 Case 1: Path goes through root, connecting left + root + right
// This path cannot extend upward (it’s complete).

      int koi_ek_accha=max(l,r)+root->data;
//       🟨 Case 2: Path goes through root and one child
// This can be extended upward to parent — so this is what we’ll return.

      int only_root_accha=root->data;
      // 🟦 Case 3: Path takes only the root node itself, no children.

      maxSum=max({maxSum,niche_hi_milgaya_answer,koi_ek_accha,only_root_accha});
      // ✅ We check all possible path sums that include this root.

      return max(koi_ek_accha,only_root_accha);
      // Finally, return the best upward extendable sum:
//       You can only extend one side upward to your parent.
// So return the best single-branch path (either left or right + root).
// Because the parent can only continue one side of your path —
// if you return both sides (l + r + root->data), you’d form a “V” shape, which breaks the path continuity.
// So we only return the best single branch to parent.

  }
    int findMaxSum(Node *root) {
        // code here
        int maxSum=INT_MIN;
        dfs(root,maxSum);
        return maxSum;
    }
};

// 🕒 Time and 🧮 Space Complexity
// Time Complexity → O(N)
// Each node is visited exactly once.
// At each node, only O(1) operations (comparisons, additions, etc.) are done.
// Space Complexity → O(H)
// Where H = height of the tree.
// Space comes from the recursive call stack.
// In the worst case (skewed tree) → H = N → O(N).
// In the best case (balanced tree) → H = logN → O(logN).





// Let’s go in detail about all four path shapes —
// •, —, Λ, and V —
// and see how they behave, when they occur, and which ones are used in practice.

// 🌿 1️⃣ Shape: Single Node (•)
//     5

// 📘 Meaning:

// Path includes only one node.

// It does not go to any child or parent.

// This is the smallest possible path in a tree.

// 🧠 Formula:
// path_sum = root->data

// ✅ When Used:

// As a base case in recursion (if(root==NULL) return 0;).

// Used when all child paths are negative — we choose just the node itself.

// 🧩 In Code:
// int only_root_accha = root->data;

// 🟢 Importance:

// ✔ Always exists
// ✔ Used in every recursive call
// ✔ Smallest unit for combining other shapes

// 🌴 2️⃣ Shape: Linear Path (—)
//     10
//    /
//   5
//  /
// 3


// or

// 3 → 5 → 10

// 📘 Meaning:

// Path goes in one direction (either all left or all right).

// It can continue upward or downward.

// This shape is extendable to parent — can grow longer.

// 🧠 Formula:
// path_sum = max(left_path, right_path) + root->data

// ✅ When Used:

// When you return from DFS to parent — parent can extend it.

// Used for return values in recursion.

// 🧩 In Code:
// int koi_ek_accha = max(l, r) + root->data;
// return max(koi_ek_accha, only_root_accha);

// 🟢 Importance:

// ✔ Used for returning to parent
// ✔ Represents extendable path
// ✔ Used in Diameter of Tree, Max Path Sum, etc.

// 🌳 3️⃣ Shape: Reverse V (Λ) — “peak shape”
//       10
//      /  \
//     2    10
//    / \     \
//   20  1     -25
//              /  \
//             3    4


// Consider this subpart:

//       10
//      /  \
//     2    10


// → Path: 20 → 2 → 10 → 10

// This forms a Λ (reverse V) shape.

// 📘 Meaning:

// Path passes through a node and connects both children.

// Starts from left child, goes up to parent, and down to right child.

// This is a complete path — cannot go further up.

// 🧠 Formula:
// path_sum = left_path + root->data + right_path

// ✅ When Used:

// To update global maximum path sum (maxSum).

// Not returned to parent — just considered for local maximum.

// 🧩 In Code:
// int niche_hi_milgaya_answer = l + r + root->data;
// maxSum = max({maxSum, niche_hi_milgaya_answer, koi_ek_accha, only_root_accha});

// 🟢 Importance:

// ✔ Used in Maximum Path Sum
// ✔ Used in Tree Diameter logic (where length = left + right + 1)
// ✔ Represents the best local answer

// 🍂 4️⃣ Shape: V shape — “valley shape” ❌ (not valid)
//      10
//     /  \
//    20  30


// If you imagine a “V”, that means the path goes downward from the root into both branches.
// But that’s not one continuous path — because there’s no way to move down two directions simultaneously.

// 📘 Meaning:

// Looks like a V visually, but not a single path.

// There’s no single chain of connected edges from one node to another.

// Breaks the definition of “path”.

// ❌ Not Used Because:

// Tree paths must be continuous (no splits or forks).

// A “V” means splitting into two — which is two separate paths, not one.

// 🟢 Importance:

// ✖ Not valid for path problems
// ✖ Never appears in path-sum or diameter logic

// 🧭 5️⃣ Summary Table
// Shape	Visual	Path Direction	Extendable?	Used For	Valid?
// •	Single Node	None	No	Base case	✅
// —	Linear	One side	Yes	Return to parent	✅
// Λ	Reverse V	Both sides (through node)	No	Update max/global sum	✅
// V	Split downwards	Two sides downward	No	—	❌ Invalid
// 🌟 Which Shape is Most Used?
// Shape	Use Frequency	Explanation
// — (Linear)	⭐⭐⭐⭐	Used in every recursion return to propagate best single-branch path upward
// Λ (Reverse V)	⭐⭐⭐	Used locally to update global maximum sum
// • (Single Node)	⭐⭐	Always part of recursion base
// V	❌	Never valid for a continuous path

// So the most used ones are:

// 🔹 — → for returning (extendable path)
// 🔹 Λ → for checking maximum (complete path)

// 🧩 Analogy with Human Climbing:

// Imagine each node as a mountain peak:

// • = standing on one mountain

// — = climbing up/down one side

// Λ = crossing from one mountain over the peak to another

// V = trying to go down both sides at once — impossible 😅