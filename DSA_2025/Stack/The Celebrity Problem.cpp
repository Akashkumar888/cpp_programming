
class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        // code here
        int n=mat.size();
        stack<int>st;
        for(int i=n-1;i>=0;i--)st.push(i);
        while(st.size()>1){
            int first=st.top();
            st.pop();
            int second=st.top();
            st.pop();
            if(mat[first][second] && !mat[second][first])st.push(second);
            else if(mat[second][first] && !mat[first][second])st.push(first);
        }
        if(st.empty())return -1;
        int celebrity=st.top();
        st.pop();
        int rowSum=0,colSum=0;
        for(int i=0;i<n;i++){
            rowSum+=mat[celebrity][i];
            colSum+=mat[i][celebrity];
        }
        if(rowSum==1 && colSum==n)return celebrity;
        if(rowSum==n && colSum==1)return celebrity;
        return -1;
    }
};



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




class Solution {
public:
    int celebrity(vector<vector<int>>& mat) {
        int n = mat.size();
        int cand = 0;

        // Step 1: Find potential celebrity
        for (int i = 1; i < n; i++) {
            if (mat[cand][i] == 1) cand = i; 
        }

        // Step 2: Verify candidate
        for (int i = 0; i < n; i++) {
            if (i == cand) continue;
            if (mat[cand][i] == 1 || mat[i][cand] == 0) return -1;
        }

        return cand;
    }
};

// ✅ Final Answer
// Time Complexity: O(n)
// Space Complexity: O(1)

