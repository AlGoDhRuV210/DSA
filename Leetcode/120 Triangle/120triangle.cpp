class Solution
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int n = triangle.size();
        // vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
        vector<int> prev(n, INT_MAX);
        prev[0] = triangle[0][0];
        if (n == 1)
            return prev[0];
        for (int i = 0; i < n; i++)
        {
            vector<int> cur(n, INT_MAX);
            for (int j = 0; j <= i; j++)
            {
                if (i == 0 && j == 0)
                {
                    cur[j] = triangle[0][0];
                    continue;
                }
                long long up = INT_MAX, down = INT_MAX;
                if (i - 1 >= 0 && prev[j] != INT_MAX)
                    up = prev[j] + triangle[i][j];
                if (j - 1 >= 0 && i - 1 >= 0 && prev[j - 1] != INT_MAX)
                    down = prev[j - 1] + triangle[i][j];
                cur[j] = min(up, down);
            }
            prev = cur;
        }
        return *min_element(prev.begin(), prev.end());
    }
};
