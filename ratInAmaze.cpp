void solve(int i, int j, vector<vector<int>>& mat, int n, vector<string>& ans, string str,vector<vector<int>>&vis) {
    if (i == n - 1 && j == n - 1) {
        ans.push_back(str);
        return;
    }

    // Going Right
    if (j < n - 1 && mat[i][j + 1] == 1&&vis[i][j+1]!=1) {
        vis[i][j]=1;
        solve(i, j + 1, mat, n, ans, str + 'R',vis);
        vis[i][j]=0;
    }
    // Going Left
    if (j > 0 && mat[i][j - 1] == 1&&vis[i][j-1]!=1) {
        vis[i][j]=1;
        solve(i, j - 1, mat, n, ans, str + 'L',vis);
        vis[i][j]=0;
    }
    // Going Down
    if (i < n - 1 && mat[i + 1][j] == 1&&vis[i+1][j]!=1) {
        vis[i][j]=1;
        solve(i + 1, j, mat, n, ans, str + 'D',vis);
        vis[i][j]=0;
    }
    // Going Up
    if (i > 0 && mat[i - 1][j] == 1&&vis[i-1][j]!=1) {
        vis[i][j]=1;
        solve(i - 1, j, mat, n, ans, str + 'U',vis);
        vis[i][j]=0;
    }
    // vis[i][j]=0;
}

vector<string> ratMaze(vector<vector<int>>& mat) {
        int n = mat.size();
    vector<vector<int>>vis(n,vector<int>(n,0));
    vector<string> ans;

    solve(0, 0, mat, n, ans, "",vis);
    return ans;
}
