
class Solution {
  public:
    string findLargest(vector<int> &arr) {
        // code here
        int n=arr.size();
        vector<string>ans;
        for(int &num:arr)ans.push_back(to_string(num));
        auto lambda=[&](string s1,string s2){
          return s1+s2>s2+s1;// place s1 before s2 if s1+s2 is lexicographically larger
        };
        sort(ans.begin(),ans.end(),lambda);
        string result="";
        for(string &str:ans)result+=str;
        while (result.size() > 1 && result[0] == '0') {
            result.erase(0, 1); // erase first character
        }
        return result;
    }
};


