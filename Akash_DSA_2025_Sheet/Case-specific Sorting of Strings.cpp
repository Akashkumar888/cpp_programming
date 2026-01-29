
class Solution {
  public:
    string caseSort(string& s) {
        // code here
        int n=s.size();
        vector<char>lower,upper;
         // Separate characters by case
        for(int i=0;i<n;i++){
            if(s[i]>='a' && s[i]<='z')lower.push_back(s[i]);
            else upper.push_back(s[i]);
        }
          // Sort both groups
        sort(lower.begin(),lower.end());
        sort(upper.begin(),upper.end());
        
        // Reconstruct the sorted string
        int i=0,j=0;
        for(int k=0;k<n;k++){
            if(s[k]>='a' && s[k]<='z'){
                s[k]=lower[i];
                i++;
            }
            else {
                s[k]=upper[j];
                j++;
            }
        }
        return s;
    }
};

