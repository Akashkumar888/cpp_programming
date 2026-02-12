
// Binary Search on Answer, we often need the ceiling division to calculate how many parts or operations are needed.
// A common expression you see is:
// (nums[i] + mid - 1) / mid

// or
// (nums[i] + k - 1) / k
// Let’s understand why this works and how to remember it easily.

// 1. What is Ceiling Division?
// Normal integer division in C++:
// 7 / 3 = 2   (floor division)
// But mathematically:
// ceil(7 / 3) = 3
// Because:
// 7 = 3 + 3 + 1

// So we need 3 parts.
// 2. Formula for Ceiling Division
// General formula:
// ceil(a / b) = (a + b - 1) / b
// Example:
// a = 7
// b = 3
// (7 + 3 - 1) / 3
// = 9 / 3
// = 3
// Correct ceiling value.
// 3. Why (a + b − 1)?
// Think of it like forcing the remainder to become a full division.
// If:
// a % b != 0
// we must add one more part.
// So:
// a + (b − 1)
// pushes the value to the next multiple.
// 4. Binary Search on Answer Example
// Typical problem:
// Koko Eating Bananas
// We calculate how many hours needed at speed mid:
// hours += ceil(pile / mid)
// In C++:
// hours += (pile + mid - 1) / mid;
// 5. How to Remember This Formula (Easy Trick)
// Trick 1: “Add divisor minus one”
// Whenever you see:
// ceil(a / b)
// Just think:
// a + (b - 1)
// -----------
//      b
// Trick 2: Think in Words
// Instead of:
// a / b
// Think:
// “How many full groups of size b do I need to cover a items?”
// If any remainder exists → one extra group.
// So:
// (a + b − 1) / b
// Trick 3: Memory Shortcut
// Just memorize this pattern:
// ceil(a / b) → (a + b − 1) / b
// It appears in:
// Koko Eating Bananas
// Minimum Speed
// Shipping Packages
// Split Array problems
// Any “number of groups” logic
// 6. Alternative Ways to Do Ceiling
// Method 1: Using remainder
// int ceil_div = a / b;
// if (a % b != 0) ceil_div++;
// Method 2: Using floating point
// int ceil_div = ceil((double)a / b);
// ⚠️ Not recommended in competitive programming due to precision and speed.
// 7. Quick Comparison
// Method	Code	Recommended
// Formula	(a + b - 1) / b	✅ Best
// Remainder check	a/b + (a%b!=0)	Good
// Floating point	ceil(a/b)	❌ Avoid
// 8. One-Line Memory Rule
// Whenever you see “ceil division” → add divisor − 1 to numerator.
// ceil(a / b) = (a + b − 1) / b


class Solution {
  public:
  bool isPossible(vector<int>&arr,int n,int mid,int k){
      int hours=0;
      for(int i=0;i<n;i++){
          // ceil(a / b) = (a + b − 1) / b
          // (arr[i]/mid)=(arr[i]+mid-1 / mid)
          hours+=(arr[i]+mid-1)/mid;
          if(hours>k)return false;
      }
      return true;
  }
    int kokoEat(vector<int>& arr, int k) {
        // Code here
        int n=arr.size();
        int l=1;
        int r=*max_element(arr.begin(),arr.end());
        int minHours=r;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(isPossible(arr,n,mid,k)){
                minHours=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        return minHours;
    }
};

// Quick Memory Rule
// If the problem says:
// “Minimum speed”
// l = 1
// r = max(array)


// “Minimum capacity / load”
// l = max(array)
// r = sum(array)
