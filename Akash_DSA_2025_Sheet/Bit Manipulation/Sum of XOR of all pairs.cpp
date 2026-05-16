
class Solution {
  public:
    long long sumXOR(vector<int> &arr) {
        // code here
        int n=arr.size();
        long long totalSum=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                totalSum+=(arr[i]^arr[j]);
            }
        }
        return totalSum;
    }
};


// 🔥 Key Understanding (VERY IMPORTANT)
// 👉 Why count1 * count0?

// Pair contributes 1 in XOR only when bits are different:
// (1,0) or (0,1)

// 👉 Number of such pairs:
// count1 × count0


class Solution {
  public:
    long long sumXOR(vector<int> &arr) {
        int n = arr.size();
        long long totalSum = 0;

        // check each bit
        for(int bits = 0; bits <= 31; bits++){
            
            long long count1 = 0;

            // count numbers with current bit = 1
            for(int &num : arr){
                int setBit=num & (1 << bits);
                if(setBit){
                    count1++;
                }
            }
            long long count0 = n - count1;
            // contribution of this bit

            // Each such pair contributes (2^bit) to the answer
            long long contribution = (count1 * count0) * (1LL << bits);
            totalSum+=contribution;
        }
        return totalSum;
    }
};