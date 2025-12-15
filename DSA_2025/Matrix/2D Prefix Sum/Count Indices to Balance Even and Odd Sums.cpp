class Solution {
  public:
    int cntWays(vector<int>& arr) {
        int n = arr.size();
        // total sum of even and odd indexed elements
        int totalEvenSum = 0, totalOddSum = 0;
        for(int i = 0; i < n; i++){
            if(i % 2 == 0) totalEvenSum += arr[i];
            else totalOddSum += arr[i];
        }
        // prefix sums (before index i)
        int prevEvenSum = 0, prevOddSum = 0;
        int count = 0;
        for(int i = 0; i < n; i++){
            // suffix sums (after index i)
            int nextEvenSum = totalEvenSum - prevEvenSum;
            int nextOddSum  = totalOddSum  - prevOddSum;

            // remove current element from suffix
            if(i % 2 == 0) nextEvenSum -= arr[i];
            else nextOddSum -= arr[i];

            /*
              After removing arr[i]:
              - elements after i change parity
              - so nextEven goes to odd
              - nextOdd goes to even
            */
            int curEvenSum = prevEvenSum + nextOddSum;
            int curOddSum  = prevOddSum  + nextEvenSum;

            // if even sum == odd sum → valid way
            if(curEvenSum == curOddSum)
                count++;

            // update prefix sums for next iteration
            if(i % 2 == 0) prevEvenSum += arr[i];
            else prevOddSum += arr[i];
        }
        return count;
    }
};
