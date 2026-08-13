class Solution
{
    const int col[4] = {-1, 0, 1, 0};
    const int row[4] = {0, -1, 0, 1};

public:
    void bfs(queue<pair<int, int>> &q, vector<vector<int>> &vis, vector<vector<char>> &board)
    {
        int m = board.size();
        int n = board[0].size();
        while (!q.empty())
        {
            int i = q.front().first;
            int j = q.front().second;

            q.pop();
            for (int k = 0; k < 4; k++)
            {
                int newrow = i + row[k];
                int newcol = j + col[k];
                if (newrow >= 0 && newrow < m && newcol >= 0 && newcol < n && !vis[newrow][newcol] &&
                    board[newrow][newcol] == 'O')
                {
                    vis[newrow][newcol] = 1;
                    q.push({newrow, newcol});
                }
            }
        }
    }
    void solve(vector<vector<char>> &board)
    {
        int m = board.size();
        int n = board[0].size();

        vector<vector<int>> vis(m, vector<int>(n, 0));
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++)
        {
            if (board[i][0] == 'O' && !vis[i][0])
            {
                vis[i][0] = 1;
                q.push({i, 0});
            }
            if (board[i][n - 1] == 'O' && !vis[i][n - 1])
            {
                vis[i][n - 1] = 1;
                q.push({i, n - 1});
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (board[0][i] == 'O' && !vis[0][i])
            {
                vis[0][i] = 1;
                q.push({0, i});
            }
            if (board[m - 1][i] == 'O' && !vis[m - 1][i])
            {
                vis[m - 1][i] = 1;
                q.push({m - 1, i});
            }
        }
        bfs(q, vis, board);

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (!vis[i][j] && board[i][j] == 'O')
                {
                    vis[i][j] = 1;
                    board[i][j] = 'X';
                }
            }
        }
    }
};