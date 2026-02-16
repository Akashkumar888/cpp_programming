
class Solution {
  public:
  //Find the count of positive numbers smaller or equal to n such that the difference between the number and sum of its digits is greater than or equal to given specific value d.
//   ✅ Correct Thinking Approach
// We want:
// x - sumOfDigits(x) >= d
// Rewrite:
// x >= d + sumOfDigits(x)
// We need to find smallest x satisfying condition.
// Because after some point, MOST numbers will satisfy it.

// 🎯 Correct Binary Search Strategy
// Instead of counting manually:
// Use binary search to find smallest valid x
// If smallest valid = ans
// Then result = n - ans + 1

  //These are 10, 11, 12 and 13.
  // 10-1 =9>2
  // 11-2 =9>2
  // 12-3 =9>2
  // 13-4 =9>2
  int sumOfDigits(int num){
      int sum=0;
      while(num>0){
          int rem=num%10;
          sum+=rem;
          num=num/10;
      }
      return sum;
  }
    int getCount(int n, int d) {
        // code here
        int l=1;
        int r=n;
        int ans=-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(mid - sumOfDigits(mid) >= d){
                ans=mid;
                r=mid-1;   // move left to find smaller valid
            }
            else{
                l=mid + 1;
            }
        }
        if(ans==-1) return 0;
        return n - ans + 1;// just like length j - i + 1
    }
};

