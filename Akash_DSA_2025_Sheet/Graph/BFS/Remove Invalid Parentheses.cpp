
class Solution {
  public:
    bool isValid(string &str){
        int count = 0;
        for(char &ch : str){
            if(ch == '('){
                count++;
            }
            else if(ch == ')'){
                count--;
                if(count < 0)return false;
            }
        }
        return count == 0;
    }
    vector<string> validParenthesis(string &s) {
        vector<string> result;
        queue<string> q;
        set<string> visited;
        q.push(s);
        visited.insert(s);
        bool found = false;
        while(!q.empty()){
            string str = q.front();
            q.pop();

            // valid string found
            if(isValid(str)){
                result.push_back(str);
                found = true;
            }
            // stop going deeper
            if(found)continue;
            // remove one bracket
            
            for(int i = 0; i < str.size(); i++){
                if(str[i] != '(' && str[i] != ')'){
                    continue;
                }
                string next = str.substr(0, i) + str.substr(i + 1);

                if(visited.find(next) == visited.end()){
                    visited.insert(next);
                    q.push(next);
                }
            }
        }
        
        sort(result.begin(), result.end());
        return result;
    }
};


class Solution {
  public:
    bool isValid(string &str){
        int count = 0;
        for(char &ch : str){
            if(ch == '('){
                count++;
            }
            else if(ch == ')'){
                count--;
                if(count < 0)return false;
            }
        }
        return count == 0;
    }
    void solve(int idx,string &s,string curr,set<string> &result,int removals,int &minRemoval){
        // end reached
        if(idx == s.size()){
            if(isValid(curr)){
                if(removals < minRemoval){
                    result.clear();
                    minRemoval = removals;
                }
                if(removals == minRemoval){
                    result.insert(curr);
                }
            }
            return;
        }
        // option 1 -> remove bracket
        if(s[idx] == '(' || s[idx] == ')'){
            solve(idx + 1,s,curr,result,removals + 1,minRemoval);
        }
        // option 2 -> keep character
        curr.push_back(s[idx]);
        solve(idx + 1,s,curr,result,removals,minRemoval);
    }
    vector<string> validParenthesis(string &s) {
        set<string> result;
        int minRemoval = INT_MAX;
        solve(0,s,"",result,0,minRemoval);

        return vector<string>(result.begin(),result.end());
    }
};