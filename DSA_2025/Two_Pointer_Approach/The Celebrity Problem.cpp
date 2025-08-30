

class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        // code here
// Does not know anyone else → their row in the matrix is all 0 (except diagonal).
// Is known by everyone → their column is all 1 (except diagonal).
        int n=mat.size();
        // Step 1: Find potential celebrity
        int i=0,j=n-1;
        while(i<j){
            if(mat[i][j]==1)i++;//i knows j, so i cannot be celebrity.
            else if(mat[i][j]==0)j--;//i doesn’t know j, so j cannot be celebrity.
        }
        int cel=i;
        // int cel=j; 
        // When the loop ends: i == j.
        // So either cel = i or cel = j, both point to the same person.
        // Step 2: Verify candidate
        for(int k=0;k<n;k++){
            if(cel==k)continue;
            else if(mat[cel][k]==1 || mat[k][cel]==0)return -1;
            // If mat[cel][k] == 1 → candidate knows someone ❌ not celebrity.
           // If mat[k][cel] == 0 → someone doesn’t know candidate ❌ not celebrity.
        }
        return cel;
    }
};

