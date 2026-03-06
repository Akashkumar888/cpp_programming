
class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        int count=0;
        vector<int>rowarray(m,0);
        vector<int>colarray(n,0);
        
         for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==1){
                    rowarray[i]++;
                    colarray[j]++;
                }
            }
         }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==1 && rowarray[i]==1 && colarray[j]==1){
                    count++;
                }
            }
        }
        return count;
    }
};