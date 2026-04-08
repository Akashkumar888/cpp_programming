class Solution {
  public:
    vector<int> intersection(vector<int>& a, vector<int>& b) {
        // code here
        vector<int>result;
        set<int>st;
        for(auto &num:b)st.insert(num);
        for(auto &num:a){
            if(st.find(num)!=st.end()){
                result.push_back(num);
                st.erase(num);
            }
        }
        return result;
    }
};

class Solution {
  public:
    vector<int> intersection(vector<int>& a, vector<int>& b) {
        // code here
        int m=a.size();
        int n=b.size();
        vector<int>result;
        int i=0,j=0;
        while(i<m && j<n){
            if(a[i]<b[j])i++;
            else if(a[i]>b[j])j++;
            else{
                while(j<n && a[i]==b[j])j++;
                result.push_back(a[i]);
                i++;
            }
        }
        return result;
    }
};

class Solution {
  public:
    vector<int> intersection(vector<int>& a, vector<int>& b) {
        // code here
        int m=a.size();
        int n=b.size();
        vector<int>result;
        int i=0,j=0;
        while(i<m && j<n){
            if(a[i]<b[j])i++;
            else if(a[i]>b[j])j++;
            else{
                while(i<m && a[i]==b[j])i++;
                result.push_back(b[j]);
                j++;
            }
        }
        return result;
    }
};
