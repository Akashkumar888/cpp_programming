
class Solution {
public:
vector<int>next_smaller_index(int n,vector<int>&arr){
      vector<int>ans(n);
      ans[n-1]=n; // for index right to left 
      stack<int>st;
      st.push(n-1); // valid index
      for(int i=n-2;i>=0;i--){
         while(!st.empty() && arr[st.top()]>=arr[i])st.pop();
         ans[i]=(st.empty()?n:st.top());
         st.push(i);
      }
      return ans;
  }
  vector<int>previous_smaller_index(int n,vector<int>&arr){
      vector<int>ans(n);
      ans[0]=-1; // for index left to right
      stack<int>st;
      st.push(0); // valid index
      for(int i=1;i<n;i++){
         while(!st.empty() && arr[st.top()]>arr[i])st.pop(); // not use = for avoid duplicate
         ans[i]=(st.empty()?-1:st.top());
         st.push(i);
      }
      return ans;
  }
int find(vector<int>&arr){
    int n=arr.size();
    vector<int>nsi=next_smaller_index(n,arr);
    vector<int>psi=previous_smaller_index(n,arr);
    vector<int>width(n);
    for(int i=0;i<n;i++){
        width[i]=nsi[i]-psi[i]-1;
    }
    int maxarea=0;
    for(int i=0;i<n;i++){
       int area=width[i]*arr[i];
        maxarea=max(area,maxarea);
    }
    return maxarea;
}    
int maximalRectangle(vector<vector<char>>& matrix) {
    if(matrix.empty())return 0;
        int m=matrix.size();
        int n=matrix[0].size();
        vector<int>arr(n,0);
        int maxarea=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]=='0') arr[j]=0;
                else arr[j]++;
            }
            int area=find(arr);
            maxarea=max(area,maxarea);
        }
        return maxarea;
    }
};