
// jb bhi l or r ko mid pe le ja ya jay to while loop me while(l<r) hi rahta hai
int mini=INT_MAX;
        int maxi=INT_MIN;
        for(int i=0;i<m;i++){
            mini=min(mini,mat[i][0]);
            maxi=max(maxi,mat[i][n-1]);
        }
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

