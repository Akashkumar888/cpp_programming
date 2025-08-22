// jb bhi l or r ko mid pe le ja ya jay to while loop me while(l<r) hi rahta hai
  int countSmallerEqual(vector<int>&mat,int val){
      int l=0,r=mat.size()-1;
      while(l<=r){
          int mid=l+(r-l)/2;
          if(mat[mid]<=val)l=mid+1;
          else r=mid-1;
      }
      return l;// number of elements <= val
  }

