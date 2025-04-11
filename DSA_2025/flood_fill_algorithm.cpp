vector<vector<int>> directions = {{1,0}, {0,1}, {0,-1}, {-1,0}};

void dfs(int i, int j, int n, int m, vector<vector<int>>& image, int oldColor, int newColor) {
    if (i < 0 || i >= n || j < 0 || j >= m || image[i][j] != oldColor || image[i][j] == newColor)
        return;
    image[i][j] = newColor;
    for (auto &dir : directions) {
        int new_i = i + dir[0];
        int new_j = j + dir[1];
        dfs(new_i, new_j, n, m, image, oldColor, newColor);
    }
}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
    int n = image.size();
    int m = image[0].size();
    int oldColor = image[sr][sc];
    dfs(sr, sc, n, m, image, oldColor, newColor);
    return image;
}
