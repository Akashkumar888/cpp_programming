
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        vector<int>ans;
         map<int,vector<int>> mp; // key = i+j
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    mp[i+j].push_back(mat[i][j]);
                }
            }
            bool flip=true;
            for(auto &it: mp){
                vector<int>result=it.second;
                if(flip)reverse(result.begin(),result.end());
                ans.insert(ans.end(),result.begin(),result.end());
                flip=!flip;
        }
        return ans;
    }
};


class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        vector<int>ans;
         map<int,vector<int>> mp; // key = i+j
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    mp[i+j].push_back(mat[i][j]);
                }
            }
            bool flip=true;
            for(auto &it: mp){
                if(flip)reverse(it.second.begin(),it.second.end());
                ans.insert(ans.end(),it.second.begin(),it.second.end());
                flip=!flip;
        }
        return ans;
    }
};


class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        vector<int>ans;
         map<int,vector<int>> mp; // key = i+j
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    mp[i+j].push_back(mat[i][j]);
                }
            }
            bool flip=true;
            for(auto &it: mp){
                if(flip)reverse(it.second.begin(),it.second.end());
                for(int &num:it.second)ans.push_back(num);
                flip=!flip;
        }
        return ans;
    }
};
