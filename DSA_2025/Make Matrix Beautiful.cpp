
class Solution {
  public:
    int balanceSums(vector<vector<int>>& mat) {
        // code here
        // you are allowed to increment the value of any single cell by 1.
        int n=mat.size();
        int count1=0,count2=0;
        int maxRowSum=0;
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=0;j<n;j++){
                sum+=mat[i][j];
            }
            maxRowSum=max(maxRowSum,sum);
        }
        int maxColSum=0;
        for(int j=0;j<n;j++){
            int sum=0;
            for(int i=0;i<n;i++){
                sum+=mat[i][j];
            }
            maxColSum=max(maxColSum,sum);
        }
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=0;j<n;j++){
                sum+=mat[i][j];
            }
            count1+=maxRowSum-sum;
        }
        for(int j=0;j<n;j++){
            int sum=0;
            for(int i=0;i<n;i++){
                sum+=mat[i][j];
            }
            count2+=maxColSum-sum;
        }
        return max(count1,count2);
    }
};


// ⏱️ Time and Space Complexity
// Time Complexity: O(n^2)
// One loop to find max row sum O(n^2)
// One loop to find max column sum and total sum O(n^2)

// Space Complexity: O(1)
// No extra space used apart from variables.




// To make all rows and columns have equal sum, the total sum of the matrix should become n * targetSum where targetSum = max(maxRowSum, maxColSum)
// You just need:
// operations = n * targetSum - totalSum;

class Solution {
public:
    int balanceSums(vector<vector<int>>& mat) {
        int n = mat.size();
        int maxRowSum = 0, maxColSum = 0;
        int totalMatSum = 0;

        // Row-wise sum and total sum
        for (int i = 0; i < n; i++) {
            int rowSum = 0;
            for (int j = 0; j < n; j++) {
                rowSum += mat[i][j];
                totalMatSum += mat[i][j];  // sum elements while visiting
            }
            maxRowSum = max(maxRowSum, rowSum);
        }

        // Column-wise max
        for (int j = 0; j < n; j++) {
            int colSum = 0;
            for (int i = 0; i < n; i++) {
                colSum += mat[i][j];
            }
            maxColSum = max(maxColSum, colSum);
        }
        // To make the matrix "beautiful", you must equalize all rows and columns to the same sum.
        // The maximum among all row and column sums becomes the target that each row and column should reach.
        // If all n rows (and n columns) must sum to targetSum, and each row must have that sum, the total sum of the entire matrix should become:
        // targetSum + targetSum + ... (n times) = n * targetSum

        int targetSum  = max(maxRowSum, maxColSum);
        // This represents the extra sum needed to make all rows and columns equal to targetSum.
        return n * targetSum  - totalMatSum;
    }
};



