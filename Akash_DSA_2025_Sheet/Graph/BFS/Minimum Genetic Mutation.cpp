
class Solution {
public:
// A gene string can be represented by an 8-character long string, with choices from 'A', 'C', 'G', and 'T'.
// startGene.length == endGene.length == bank[i].length == 8
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        set<string>s(bank.begin(),bank.end());
        // s.erase(startGene);
        queue<pair<string,int>>q;
        string str="ACGT";
        q.push({startGene,0});
        set<string>visited;
        visited.insert(startGene);
        while(!q.empty()){
            string curr=q.front().first;
            int level=q.front().second;
            q.pop();
            if(curr==endGene)return level;
            for(int i=0;i<8;i++){
            char ch=curr[i];
            for(int j=0;j<str.size();j++){
                curr[i]=str[j];
                if(s.find(curr)!=s.end()){
                    q.push({curr,level+1});
                    visited.insert(curr);
                    s.erase(curr);
                }
             }
             curr[i]=ch;
            }
        }
        return -1;
    }
};


class Solution {
public:
// A gene string can be represented by an 8-character long string, with choices from 'A', 'C', 'G', and 'T'.
// startGene.length == endGene.length == bank[i].length == 8
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        set<string>s(bank.begin(),bank.end());
        // s.erase(startGene);
        queue<pair<string,int>>q;
        string str="ACGT";
        q.push({startGene,0});
        set<string>visited;
        visited.insert(startGene);
        while(!q.empty()){
            string curr=q.front().first;
            int level=q.front().second;
            q.pop();
            if(curr==endGene)return level;
            for(int i=0;i<str.size();i++){
              for(int j=0;j<8;j++){
                string ngbr=curr;
                ngbr[j]=str[i];
                if(s.find(ngbr)!=s.end()){
                    q.push({ngbr,level+1});
                    visited.insert(ngbr);
                    s.erase(ngbr);
                }
             }
            }
        }
        return -1;
    }
};
