
// User function template for C++

/* matrix : given input matrix, you are require
 to change it in place without using extra space */
//  Given a square mat[][]. The task is to rotate it by 90 degrees in clockwise direction without using any extra space.
void rotate(vector<vector<int> >& mat) {
    // Your code goes here
    int n=mat.size();
        // square matrix of size n x n.
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                swap(mat[i][j],mat[j][i]);
            }
        }
        for(int i=0;i<n;i++){
             int l=0,r=n-1;
             while(l<r){
                swap(mat[i][l],mat[i][r]);
                l++,r--;
            }
        }
}
