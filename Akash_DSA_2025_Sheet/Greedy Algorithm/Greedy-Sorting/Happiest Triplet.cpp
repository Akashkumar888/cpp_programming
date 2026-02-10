
class Solution {
  public:
    vector<int> smallestDiff(vector<int>& a, vector<int>& b, vector<int>& c) {
        // code here.
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        sort(c.begin(),c.end());
        //same size
        // 2,5,8
        // 7,10,12
        // 6,9,14
        int minDiff=INT_MAX;
        int minSum=INT_MAX;
        int i=0,j=0,k=0;
        int first=-1,second=-1,third=-1;
        while(i<a.size() && j<b.size() && k<c.size()){
            if(a[i]<=b[j] && a[i]<=c[k]){
                int maxi=max({a[i],b[j],c[k]});
                int mini=min({a[i],b[j],c[k]});
                int diff=maxi-mini;
                int sum=a[i]+b[j]+c[k];
                if(minDiff>diff || (minDiff==diff && minSum>sum )){
                    first=a[i];
                    second=b[j];
                    third=c[k];
                    minDiff=diff;
                    minSum=sum;
                }
                i++;
            }
            else if(b[j]<=a[i] && b[j]<=c[k]){
                int maxi=max({a[i],b[j],c[k]});
                int mini=min({a[i],b[j],c[k]});
                int diff=maxi-mini;
                int sum=a[i]+b[j]+c[k];
                if(minDiff>diff || (minDiff==diff && minSum>sum )){
                    first=a[i];
                    second=b[j];
                    third=c[k];
                    minDiff=diff;
                    minSum=sum;
                }
                j++;
            }
            else if(c[k]<=a[i] && c[k]<=b[j]){
                int maxi=max({a[i],b[j],c[k]});
                int mini=min({a[i],b[j],c[k]});
                int diff=maxi-mini;
                int sum=a[i]+b[j]+c[k];
                if(minDiff>diff || (minDiff==diff && minSum>sum )){
                    first=a[i];
                    second=b[j];
                    third=c[k];
                    minDiff=diff;
                    minSum=sum;
                }
                k++;
            }
        }
        vector<int>result;
        result.push_back(first);
        result.push_back(second);
        result.push_back(third);
        sort(result.begin(),result.end(),greater<int>());
        return result;
    }
};



class Solution {
  public:
    vector<int> smallestDiff(vector<int>& a, vector<int>& b, vector<int>& c) {
        // code here.
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        sort(c.begin(),c.end());
        //same size
        int minDiff=INT_MAX;
        int minSum=INT_MAX;
        int i=0,j=0,k=0;
        int first=-1,second=-1,third=-1;
        while(i<a.size() && j<b.size() && k<c.size()){
                int maxi=max({a[i],b[j],c[k]});
                int mini=min({a[i],b[j],c[k]});
                int diff=maxi-mini;
                int sum=a[i]+b[j]+c[k];
            if(a[i]<=b[j] && a[i]<=c[k]){
                if(minDiff>diff || (minDiff==diff && minSum>sum )){
                    minDiff=diff;
                    minSum=sum;
                    first=a[i];
                    second=b[j];
                    third=c[k];
                }
                i++;
            }
            else if(b[j]<=a[i] && b[j]<=c[k]){
                if(minDiff>diff || (minDiff==diff && minSum>sum )){
                    minDiff=diff;
                    minSum=sum;
                    first=a[i];
                    second=b[j];
                    third=c[k];
                }
                j++;
            }
            else if(c[k]<=a[i] && c[k]<=b[j]){
                if(minDiff>diff || (minDiff==diff && minSum>sum )){
                    minDiff=diff;
                    minSum=sum;
                    first=a[i];
                    second=b[j];
                    third=c[k];
                }
                k++;
            }
        }
        vector<int>result={first,second,third};
        sort(result.begin(),result.end(),greater<int>());
        return result;
    }
};




class Solution {
  public:
    vector<int> smallestDiff(vector<int>& a, vector<int>& b, vector<int>& c) {
        // code here.
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        sort(c.begin(),c.end());
        //same size
        int minDiff=INT_MAX;
        int minSum=INT_MAX;
        int i=0,j=0,k=0;
        int first=-1,second=-1,third=-1;
        while(i<a.size() && j<b.size() && k<c.size()){
                int maxi=max({a[i],b[j],c[k]});
                int mini=min({a[i],b[j],c[k]});
                int diff=maxi-mini;
                int sum=a[i]+b[j]+c[k];
                if(minDiff>diff || (minDiff==diff && minSum>sum )){
                    minDiff=diff;
                    minSum=sum;
                    first=a[i];
                    second=b[j];
                    third=c[k];
                }
            // move pointer of minimum element
            if(mini==a[i])i++;
            else if(mini==b[j])j++;
            else k++;
        }
        vector<int>result={first,second,third};
        sort(result.begin(),result.end(),greater<int>());
        return result;
    }
};
