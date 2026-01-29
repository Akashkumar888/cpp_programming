
class Solution {
  public:
    void setMatrixZeroes(vector<vector<int>> &mat) {
        // code here
        int n=mat.size();
        int m=mat[0].size();
        vector<bool>row(n,false);
        vector<bool>col(m,false);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    row[i]=true;
                    col[j]=true;
                }
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(row[i] || col[j])mat[i][j]=0;
            }
        }
        
    }
};

// ✅ Time Complexity:
// O(n × m)
// First nested loop: to mark zeroes.
// Second nested loop: to update the matrix.

// ✅ Space Complexity:
// O(n + m)
// One extra array for each row and column.





class Solution {
  public:
    void setMatrixZeroes(vector<vector<int>> &mat) {
        // code here
        int n=mat.size();
        int m=mat[0].size();
        
        bool first_row=false;
        bool first_col=false;
        // Step 1: Check if first row has any zero
        for(int j=0;j<m;j++){
            if(mat[0][j]==0){
                first_row=true;// first row
                break;
            }
        }
        // Step 2: Check if first column has any zero
        for(int i=0;i<n;i++){
            if(mat[i][0]==0){
                first_col=true;//first column 
                break;
            }
        }
        // Step 3: Use first row and column as markers
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(mat[i][j]==0){
                    mat[0][j]=0;// first row 
                    mat[i][0]=0;// first col
                }
            }
        }
        // Step 4: Zero out cells based on markers
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(mat[i][0]==0 || mat[0][j]==0)mat[i][j]=0;
            }
        }
        // Step 5: Zero out first row if needed
        if(first_col){
            for(int i=0;i<n;i++){
                mat[i][0]=0;//first column 
            }
        }
        // Step 6: Zero out first column if needed
        if(first_row){
            for(int j=0;j<m;j++){
                mat[0][j]=0;// first row
            }
        }
    }
};

// ✅ Time Complexity:
// O(n × m)
// First scan for 0s in first row & col → O(n + m)
// Second scan for remaining cells → O(n × m)
// Final scan to apply zeroes → O(n × m)

// ✅ Space Complexity:
// O(1) (Constant extra space)
// No auxiliary space used except a few boolean variables (first_row, first_col).

