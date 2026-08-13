class Solution
{
private:
    vector<int> col = {-1, 0, 1, 0};
    vector<int> row = {0, -1, 0, 1};

public:
    void dfs(queue<pair<int, int>> q, vector<vector<int>> &adj, vector<vector<int>> &ans)
    {
        int m = adj.size();
        int n = adj[0].size();
        while (!q.empty())
        {
            int i = q.front().first;
            int j = q.front().second;

            q.pop();
            for (int k = 0; k < 4; k++)
            {
                int newrow = i + row[k];
                int newcol = j + col[k];
                if (newrow >= 0 && newrow < m && newcol >= 0 && newcol < n)
                {
                    if (ans[newrow][newcol]==-1)
                    {
                        ans[newrow][newcol] = 1 + ans[i][j];
                        q.push({newrow, newcol});
                    }
                }
            }
        }
    }
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> ans(m, vector<int>(n, -1));

        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (mat[i][j] == 0)
                {
                    ans[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        dfs(q, mat, ans);

        return ans;
    }
};