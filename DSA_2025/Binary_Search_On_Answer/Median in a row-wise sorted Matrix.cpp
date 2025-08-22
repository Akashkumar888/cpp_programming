// 2d array me kisi element ko search krna hai to use binary search on answer 
class Solution {
  public:
  int countSmallerEqual(vector<int>&mat,int val){
      int l=0,r=mat.size()-1;
      while(l<=r){
          int mid=l+(r-l)/2;
          if(mat[mid]<=val)l=mid+1;
          else r=mid-1;
      }
      return l;// number of elements <= val
  }
    int median(vector<vector<int>> &mat) {
        // code here
        int m=mat.size();
        int n=mat[0].size();
        int mini=INT_MAX;
        int maxi=INT_MIN;
        for(int i=0;i<m;i++){
            mini=min(mini,mat[i][0]);
            maxi=max(maxi,mat[i][n-1]);
        }
        int k=(m*n+1)/2;// median index (1-based)
        // jb bhi l or r ko mid pe le ja ya jay to while loop me while(l<r) hi rahta hai
        while(mini<maxi){
            int mid=mini+(maxi-mini)/2;
            int count=0;
            // count how many elements <= mid
            for(int i=0;i<m;i++){
                count+=countSmallerEqual(mat[i],mid);
            }
            if(count<k)mini=mid+1;// need larger value
            else maxi=mid;// possible answer
        }
        return mini;
    }
};
