class Solution
{
    int row[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int col[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

public:
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
            return -1;
        vector<vector<int>> v(n, vector<int>(n, INT_MAX));

        queue<tuple<int, int, int>> pq;
        pq.push({1, 0, 0});

        int ans = INT_MAX;
        vector<vector<int>> dis(n, vector<int>(n, INT_MAX));
        dis[0][0] = 1;
        while (!pq.empty())
        {
            auto t = pq.front();
            pq.pop();
            int i = get<1>(t);
            int j = get<2>(t);
            int dist = get<0>(t);

            if (i == n - 1 && j == n - 1)
            {
                return dis[n - 1][n - 1];
            }
            for (int k = 0; k < 8; k++)
            {
                int nrow = i + row[k];
                int ncol = j + col[k];
                if (nrow < 0 || ncol < 0 || nrow >= n || ncol >= n || grid[nrow][ncol] == 1)
                    continue;
                if (dis[nrow][ncol] > dist + 1)
                {
                    dis[nrow][ncol] = dist + 1;
                    pq.push({dist + 1, nrow, ncol});
                }
            }
        }
        if (dis[n - 1][n - 1] == INT_MAX)
            return -1;

        return dis[n - 1][n - 1];
    }
};