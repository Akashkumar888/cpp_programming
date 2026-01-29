
class Solution {
  public:
    int findLength(vector<int> &color, vector<int> &radius) {
        // code here
        stack<int>st1,st2;
        int n=color.size();
        for(int i=0;i<n;i++){
            if(!st1.empty() && !st2.empty() && st1.top()==color[i] && st2.top()==radius[i]){
                st1.pop();
                st2.pop();
            }
            else {
                st1.push(color[i]);
                st2.push(radius[i]);
            } 
        }
     return st1.size();   
    }
};

