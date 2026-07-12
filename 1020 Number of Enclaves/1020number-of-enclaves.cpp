class Solution {
public:
    const int col[4] = {-1, 0, 1, 0};
    const int row[4] = {0, -1, 0, 1};
    void dfs(vector<vector<int>>& grid, int i, int j,
             vector<vector<int>>& vis) {
        int m = grid.size();
        int n = grid[0].size();

        for (int k = 0; k < 4; k++) {
            int newrow = i + row[k];
            int newcol = j + col[k];
            if (newrow >= 0 && newrow < m && newcol >= 0 && newcol < n &&
                grid[newrow][newcol] == 1 && !vis[newrow][newcol]) {
                vis[newrow][newcol] = 1;
                dfs(grid, newrow, newcol, vis);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> vis(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            if (!vis[i][0] && grid[i][0]==1) {
                vis[i][0] = 1;
                dfs(grid, i, 0, vis);
            }
            if (!vis[i][n - 1] && grid[i][n-1]==1) {
                vis[i][n - 1] = 1;
                dfs(grid, i, n - 1, vis);
            }
        }
        for (int i = 0; i < n; i++) {
            if (!vis[0][i] && grid[0][i]==1) {
                vis[0][i] = 1;
                dfs(grid, 0, i, vis);
            }
            if (!vis[m - 1][i] && grid[m-1][i]==1) {
                vis[m - 1][i] = 1;
                dfs(grid, m - 1, i, vis);
            }
        }

        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!vis[i][j] && grid[i][j] == 1) {
                    vis[i][j] = 1;
                    ans++;
                }
            }
        }
        return ans;
    }
};