class Solution {
  public:
    // Find determinant using recursion
    int determinant(vector<vector<int>>& mat, int n){
        // Base Case
        if(n == 1){
            return mat[0][0];
        }
        int det = 0;
        int sign = 1;
        // Expand along first row
        for(int col = 0; col < n; col++){
            vector<vector<int>> subMat;
            // Create submatrix
            for(int i = 1; i < n; i++){
                vector<int> row;
                for(int j = 0; j < n; j++){
                    // Skip current column
                    if(j == col) continue;
                    row.push_back(mat[i][j]);
                }
                subMat.push_back(row);
            }
            // Cofactor Expansion
            det += sign * mat[0][col] * determinant(subMat, n - 1);
            // Alternate sign
            sign *= -1;
        }
        return det;
    }
    int countSpanTree(int n, vector<vector<int>>& edges) {
        // Special Case
        if(n == 1) return 1;
        // Step 1:
        // Create Laplacian Matrix
        vector<vector<int>> mat(n, vector<int>(n, 0));
        /*
            According to Kirchhoff's Matrix Tree Theorem:
            if i != j:
                mat[i][j] = -1 if edge exists
                mat[i][j] = 0 otherwise
            if i == j:
                mat[i][j] = degree of vertex
        */
        // Build Matrix
        for(auto &edge : edges){
            int u = edge[0];
            int v = edge[1];

            // diagonal
            // Degree of vertex
            mat[u][u]++;
            mat[v][v]++;

            // Adjacent vertices
            mat[u][v] = -1;
            mat[v][u] = -1;
        }
        // Step 2:
        // Delete any one row and one column
        // Create Cofactor Matrix
        vector<vector<int>> cofactor(n-1,vector<int>(n-1));
        for(int i = 0; i < n - 1; i++){
            for(int j = 0; j < n - 1; j++){
                cofactor[i][j] = mat[i][j];
            }
        }
        // Step 3:
        // Determinant of cofactor matrix
        // gives number of spanning trees
        return determinant(cofactor, n - 1);
    }
};


class Solution {
  public:
    // find determinant using recursion
    int determinant(vector<vector<int>>& mat, int n){
        // base case
        if(n == 1)return mat[0][0];
        int det = 0;
        int sign = 1;
        for(int col = 0; col < n; col++){
            vector<vector<int>> subMat;
            // create submatrix
            for(int i = 1; i < n; i++){
                vector<int> row;
                for(int j = 0; j < n; j++){
                    if(j == col) continue;
                    row.push_back(mat[i][j]);
                }
                subMat.push_back(row);
            }
            det += sign * mat[0][col] * determinant(subMat, n - 1);
            sign *= -1;
        }
        return det;
    }
    int countSpanTree(int n, vector<vector<int>>& edges) {
        if(n == 1) return 1;
        // Laplacian Matrix
        vector<vector<int>> lap(n,vector<int>(n, 0));

        // build graph
        for(auto &edge : edges){
            int u = edge[0];
            int v = edge[1];
            // degree
            lap[u][u]++;
            lap[v][v]++;

            // adjacency
            lap[u][v]--;
            lap[v][u]--;
        }
        // create cofactor matrix
        vector<vector<int>> cofactor(n - 1,vector<int>(n - 1));

        for(int i = 0; i < n - 1; i++){
            for(int j = 0; j < n - 1; j++){
                cofactor[i][j] = lap[i][j];
            }
        }
        // determinant gives answer
        return determinant(cofactor, n - 1);
    }
};

