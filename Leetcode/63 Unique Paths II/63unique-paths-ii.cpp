class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<int> prev(n, -1);
        for (int i = 0; i < m; i++)
        {
            vector<int> cur(n, -1);
            for (int j = 0; j < n; j++)
            {
                if (obstacleGrid[i][j] == 1)
                {
                    cur[j] = 0;
                    continue;
                }
                if (i == 0 && j == 0)
                {
                    cur[j] = 1;
                    continue;
                }
                int left = 0, right = 0;
                if (i - 1 >= 0)
                    
                    left = prev[j];
                // left = dp[i - 1][j];
                if (j - 1 >= 0)
                    right = cur[j - 1];
                // right = dp[i/][j - 1];
                cur[j] = left + right;
            }
            prev = cur;
        }
        return prev[n - 1];
    }
};