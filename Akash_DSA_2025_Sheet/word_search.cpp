#include <vector>
using namespace std;

vector<vector<int>> directions = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};

bool dfs(int i, int j, int k, int n, int m, vector<vector<char>>& mat, string& word) {
    if (k == word.size()) return true;  
    if (i < 0 || i >= n || j < 0 || j >= m || mat[i][j] == '@' || mat[i][j] != word[k])  
        return false;  

    char temp = mat[i][j];  
    mat[i][j] = '@';  

    for (auto& dir : directions) {  
        int new_i = i + dir[0], new_j = j + dir[1];  
        if (dfs(new_i, new_j, k + 1, n, m, mat, word)) return true;  
    }  

    mat[i][j] = temp;  
    return false;  
}

bool isWordExist(vector<vector<char>>& mat, string& word) {  
    int n = mat.size(), m = mat[0].size();  
    for (int i = 0; i < n; i++) {  
        for (int j = 0; j < m; j++) {  
            if (mat[i][j] == word[0] && dfs(i, j, 0, n, m, mat, word))  
                return true;  
        }  
    }  
    return false;  
}
