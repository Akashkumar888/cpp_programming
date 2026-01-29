
class Solution {
  public:
// size n x m. Each row in the matrix is sorted in non-decreasing order. 
// Your task is to merge all the rows and return a single sorted array 
// that contains all the elements of the matrix.
    vector<int> mergeArrays(vector<vector<int>> &mat) {
        // Code here
        // increasing order 
        vector<int>result;
        int n=mat.size();// rows
        int m=mat[0].size();//cols
        int k=n; // how many rows here
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)pq.push(mat[i][j]);
        }
        while(!pq.empty()){
            result.push_back(pq.top());
            pq.pop();
        }
        return result;
    }
};


class Solution {
  public:
// size n x m. Each row in the matrix is sorted in non-decreasing order. 
// Your task is to merge all the rows and return a single sorted array 
// that contains all the elements of the matrix.
    vector<int> mergeArrays(vector<vector<int>> &mat) {
        // Code here
        // increasing order 
        typedef vector<int> V;
        vector<int>result;
        int n=mat.size();// rows
        int m=mat[0].size();//cols
        int k=n; // how many rows here
        priority_queue<V,vector<V>,greater<V>>pq;
        for(int i=0;i<n;i++){
            pq.push(mat[i]);
        }
        // Delete first element of each inner vector
        //  row.erase(row.begin());  // removes the first element
        while(!pq.empty()){
            // Copy top element
            vector<int> topVec = pq.top();
            pq.pop();// Remove it from the heap
    
            // Take first element
            result.push_back(topVec.front());
    
            // Erase first element from vector
            topVec.erase(topVec.begin());
    
            // If it still has elements, push it back
            if (!topVec.empty()) pq.push(topVec);
        }
        return result;
    }
};


class Solution {
  public:
// size n x m. Each row in the matrix is sorted in non-decreasing order. 
// Your task is to merge all the rows and return a single sorted array 
// that contains all the elements of the matrix.
    vector<int> mergeArrays(vector<vector<int>> &mat) {
        // Code here
        // increasing order 
        typedef pair<int,pair<int,int>>P;
        vector<int>result;
        int n=mat.size();// rows
        int m=mat[0].size();//cols
        int k=n; // how many rows here
        priority_queue<P,vector<P>,greater<P>>pq;
        for(int i=0;i<n;i++){
            pq.push({mat[i][0],{i,0}});
        }
        while(!pq.empty()){
            result.push_back(pq.top().first);
            int row=pq.top().second.first;
            int col=pq.top().second.second;
            pq.pop();
            if(col+1<m)pq.push({mat[row][col+1],{row,col+1}});
        }
        return result;
    }
};
