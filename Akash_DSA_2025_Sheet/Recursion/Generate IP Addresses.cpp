
class Solution {
public:
    bool validPart(string &part) {
        if(part.size() > 1 && part[0] == '0')return false;
        int value = stoi(part);
        return value >= 0 && value <= 255;
    }
    void solve(int index,int partsUsed,string &s,string currentIP,vector<string>&result) {
        if(partsUsed == 4 && index == s.size()) {
            currentIP.pop_back(); 
            result.push_back(currentIP);
            return;
        }
        if(partsUsed >= 4)return;
        for(int i = 1; i <= 3 && index + i <= s.size(); i++){
            string part = s.substr(index, i);
            if(validPart(part)){
                solve(index+i,partsUsed+1,s,currentIP + part + ".",result);
            }
        }
    }
    vector<string> generateIp(string &s) {
        vector<string>result;
        if(s.size() < 4 || s.size() > 12)return result;
        solve(0,0,s,"",result);
        return result;
    }
};