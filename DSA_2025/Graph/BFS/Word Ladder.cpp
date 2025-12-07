
// ✅ Data Structures & Algorithms → Graphs → BFS (Breadth-First Search)

// This problem is a classic example of shortest transformation / shortest mutation / shortest path using BFS.
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string>st(wordList.begin(),wordList.end());
        st.erase(beginWord);
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        while(!q.empty()){
            string word=q.front().first;
            int step=q.front().second;
            q.pop();
            if(word==endWord)return step;
            for(int i=0;i<word.size();i++){
                char temp=word[i];
                for(char ch='a';ch<='z';ch++){
                    word[i]=ch;
                    if(st.find(word)!=st.end()){
                        q.push({word,step+1});
                        st.erase(word);
                    }
                }
                word[i]=temp;
            }
        }
        return 0;
    }
};

// Similar problems in this category:
// Word Ladder (LeetCode 127)
// Open the Lock (LeetCode 752)
// Minimum Genetic Mutation (LeetCode 433) ← your exact problem
// Rotting Oranges
// Knight Moves (chessboard shortest path)
// Why BFS?
// Because:
// Every mutation costs exactly 1 step → unweighted graph
// We want the minimum number of mutations → shortest path
// BFS explores in levels → finds shortest path automatically
// Graph Interpretation:
// Each gene string is a node
// A valid mutation (1 char change) is an edge
// You search shortest path from startGene → endGene

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string>st(wordList.begin(),wordList.end());
        st.erase(beginWord);
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        while(!q.empty()){
            string word=q.front().first;
            int step=q.front().second;
            q.pop();
            if(word==endWord)return step;
            for(char ch='a';ch<='z';ch++){
              for(int i=0;i<word.size();i++){
                string ngbr=word;
                ngbr[i]=ch;
                    if(st.find(ngbr)!=st.end()){
                        q.push({ngbr,step+1});
                        st.erase(ngbr);
                    }
                }
            }
        }
        return 0;
    }
};