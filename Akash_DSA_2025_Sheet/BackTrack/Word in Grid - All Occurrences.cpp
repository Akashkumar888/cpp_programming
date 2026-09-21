
class Solution {
  public:

    vector<vector<int>> searchWord(vector<vector<char>> &mat, string word) {

        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> result;

        int dx[8] = {-1,-1,-1,0,0,1,1,1};
        int dy[8] = {-1,0,1,-1,1,-1,0,1};

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                // First character must match
                if(mat[i][j] != word[0])
                    continue;

                bool found = false;

                // Try all 8 directions
                for(int k=0;k<8;k++)
                {
                    int x = i;
                    int y = j;

                    int p = 0;

                    while(p < word.size())
                    {
                        // Outside grid
                        if(x < 0 || x >= n || y < 0 || y >= m)
                            break;

                        // Character doesn't match
                        if(mat[x][y] != word[p])
                            break;

                        x += dx[k];
                        y += dy[k];
                        p++;
                    }

                    // Complete word matched
                    if(p == word.size())
                    {
                        found = true;
                        break;
                    }
                }

                if(found)
                {
                    result.push_back({i,j});
                }
            }
        }

        return result;
    }
};