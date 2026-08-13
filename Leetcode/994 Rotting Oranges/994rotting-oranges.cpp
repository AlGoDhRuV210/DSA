class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> rotten;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 2)
                    rotten.push({i, j});
            }
        }
        int ans = 0;
        int flag = 0;

        while (!rotten.empty())
        {
            flag = 0;
            int s = rotten.size();

            for (int k = 0; k < s; k++)
            {
                int i = rotten.front().first;
                int j = rotten.front().second;
                rotten.pop();
                if (i + 1 < m)
                {
                    if (grid[i + 1][j] == 1)
                    {
                        grid[i + 1][j] = 2;
                        rotten.push({i + 1, j});
                        flag = 1;
                    }
                }
                if (i - 1 >= 0)
                {
                    if (grid[i - 1][j] == 1)
                    {
                        grid[i - 1][j] = 2;
                        rotten.push({i - 1, j});
                        flag = 1;
                    }
                }
                if (j + 1 < n)
                {
                    if (grid[i][j + 1] == 1)
                    {
                        grid[i][j + 1] = 2;
                        rotten.push({i, j + 1});
                        flag = 1;
                    }
                }
                if (j - 1 >= 0)
                {
                    if (grid[i][j - 1] == 1)
                    {
                        grid[i][j - 1] = 2;
                        rotten.push({i, j - 1});
                        flag = 1;
                    }
                }
            }
            if (flag)
                ans++;
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                    return -1;
            }
        }

        return ans;
    }
};