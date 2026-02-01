
class Solution {
public:
    string reverseByType(string s) {
        int n=s.size();
        vector<char>lowerCase;
        vector<char>specialCase;

        for(int i=0;i<n;i++) {
            if(s[i]>='a' && s[i]<='z')lowerCase.push_back(s[i]);
            else specialCase.push_back(s[i]);
        }

        reverse(specialCase.begin(),specialCase.end());
        reverse(lowerCase.begin(),lowerCase.end());

        int  i= 0,j= 0;
        for(int k=0;k<n;k++){
            if(s[k]>='a' && s[k]<='z'){
                s[k]=lowerCase[i];
                i++;
            }
            else {
                s[k] = specialCase[j];
                j++;
            }
        }
        return s;
    }
};
