class Solution
{
public:
    int col[4] = {0, 1, -1, 0};
    int row[4] = {1, 0, 0, -1};
    bool check(int t, vector<vector<int>> &grid)
    {
        if (t < grid[0][0])
            return false;
        int n = grid.size();
        vector<vector<int>> vis(n, vector<int>(n, 0));
        queue<pair<int, int>> q;
        q.push({0, 0});
        vis[0][0] = 1;
        while (!q.empty())
        {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();

            int node = n * i + j;

            for (int k = 0; k < 4; k++)
            {
                int nrow = i + row[k];
                int ncol = j + col[k];
                if (nrow < 0 || ncol < 0 || nrow >= n || ncol >= n || vis[nrow][ncol] || grid[nrow][ncol] > t)
                    continue;
                q.push({nrow, ncol});
                vis[nrow][ncol] = 1;
            }
        }
        if (vis[n - 1][n - 1])
            return true;
        return false;
    }
    int swimInWater(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int low = 0;
        int high = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                high = max(high, grid[i][j]);
            }
        }

        int t = high;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (check(mid, grid))
            {
                t = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        return t;
    }
};
