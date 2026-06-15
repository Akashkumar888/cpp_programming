
class Solution {
  public:
    bool kSubstr(string &s, int k) {
        int n = s.size();
        if(n % k != 0){
            return false;
        }
        unordered_map<string,int> mp;
        for(int i = 0; i < n; i += k){
            string block = s.substr(i, k);
            mp[block]++;
        }
        if(mp.size() == 1){
            return true;
        }
        if(mp.size() > 2){
            return false;
        }
        for(auto &it : mp){
            if(it.second == 1){
                return true;
            }
        }
        return false;
    }
};


class Solution {
  public:
    bool kSubstr(string &s, int k) {

        int n = s.size();

        if(n % k != 0){
            return false;
        }

        unordered_map<string,int> mp;

        for(int i = 0; i < n; i += k){

            string block = s.substr(i, k);

            mp[block]++;

            if(mp.size() >= 3){
                return false;
            }
        }

        int cnt = 0;

        for(auto &it : mp){

            if(it.second >= 2){
                cnt++;
            }
        }

        return cnt < 2;
    }
};


class Solution {
  public:
    bool kSubstr(string &s, int k) {

        int n = s.size();

        if(n % k != 0){
            return false;
        }

        unordered_map<string,int> mp;

        for(int i = 0; i < n; i += k){

            string block = s.substr(i, k);

            mp[block]++;
        }

        bool oneExists = false;

        for(auto &it : mp){

            if(it.second == 1){

                oneExists = true;
                break;
            }
        }

        if((mp.size() == 2 && oneExists) || mp.size() < 2){
            return true;
        }

        return false;
    }
};


class Solution {
  public:
    bool kSubstr(string &s, int k) {

        int n = s.size();

        if(n % k != 0){
            return false;
        }

        unordered_map<string,int> mp;

        for(int i = 0; i < n; i += k){

            string block = s.substr(i, k);

            mp[block]++;
        }

        if(mp.size() == 1){
            return true;
        }

        if(mp.size() != 2){
            return false;
        }

        int totalBlocks = n / k;

        for(auto &it : mp){

            if(it.second == 1 ||
               it.second == totalBlocks - 1){

                return true;
            }
        }

        return false;
    }
};

