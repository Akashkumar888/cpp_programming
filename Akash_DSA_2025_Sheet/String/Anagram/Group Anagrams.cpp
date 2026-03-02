
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>result;
        map<string,vector<string>>mp;
        for(auto &word:strs){
            string str=word;
            sort(word.begin(),word.end());
            mp[word].push_back(str);
        }
        for(auto &it:mp){
            vector<string>ans;
            for(auto &str:it.second)ans.push_back(str);
            result.push_back(ans);
        }
        return result;
    }
};


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>result;
        map<string,vector<string>>mp;
        for(auto &word:strs){
            string str=word;
            sort(word.begin(),word.end());
            mp[word].push_back(str);
        }
        for(auto &it:mp){
            result.push_back(it.second);
        }
        return result;
    }
};
