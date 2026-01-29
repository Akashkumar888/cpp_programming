
// class Solution {
// public:
//     vector<int> getRow(int rowIndex) {
//         vector<int> row(rowIndex + 1, 0);
//         row[0] = 1;
//         for (int i = 1; i <= rowIndex; ++i) {
//             for (int j = i; j >= 1; --j) {
//                 row[j] += row[j - 1];
//             }
//         }
//         return row;
//     }
// };

class Solution {
  public:
      vector<int> getRow(int rowIndex) {
          vector<int> row(rowIndex + 1);
          row[0] = 1; // C(n, 0) = 1
          for (int k = 1; k <= rowIndex; k++) {
              row[k] = (long long)row[k - 1] * (rowIndex - k + 1) / k;
          }
          return row;
      }
  };
  

  class Solution {
    public:
      vector<int> nthRowOfPascalTriangle(int n) {
          // code here
          n=n-1;
          vector<int> row(n+1);
          row[0] = 1; // C(n, 0) = 1
          for (int k = 1; k <=n; k++) {
              row[k] = (long long)row[k - 1] * (n - k + 1) / k;
          }
          return row;
          
      }
    };
    