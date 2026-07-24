class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> prev(n, -1);
        for (int i = 0; i < m; i++)
        {
            vector<int> cur(n, -1);
            for (int j = 0; j < n; j++)
            {

                if (i == 0 && j == 0)
                {
                    cur[j] = grid[i][j];
                    continue;
                }
                int left = INT_MAX, right = INT_MAX;
                if (i - 1 >= 0)

                    left = prev[j] + grid[i][j];
                // left = dp[i - 1][j];
                if (j - 1 >= 0)
                    right = cur[j - 1] + grid[i][j];
                // right = dp[i/][j - 1];
                cur[j] = min(left, right);
            }
            prev = cur;
        }
        return prev[n - 1];
    }
};