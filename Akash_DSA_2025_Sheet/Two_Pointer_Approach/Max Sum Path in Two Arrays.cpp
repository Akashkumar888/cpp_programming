
class Solution {
  public:
    int maxPathSum(vector<int> &a, vector<int> &b) {
        // Code here
        int m=a.size();
        int n=b.size();
        int i=0,j=0;
        int sum1=0,sum2=0;
        int totalSum=0;
        while(i<m && j<n){
            if(a[i]<b[j]){
                sum1+=a[i];
                i++;
            }
            else if(a[i]>b[j]){
                sum2+=b[j];
                j++;
            }
            else{
                totalSum+=max(sum1,sum2);
                totalSum+=a[i];
                sum1=0,sum2=0;
                i++,j++;
            }
        }
        while(i<m){
            sum1+=a[i];
            i++;
        }
        while(j<n){
            sum2+=b[j];
            j++;
        }
        totalSum+=max(sum1,sum2);
        return totalSum;
    }
};