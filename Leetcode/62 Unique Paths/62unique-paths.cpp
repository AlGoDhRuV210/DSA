class Solution {
public:
    int uniquePaths(int m, int n) {
        // vector<vector<int>> dp(m, vector<int>(n, -1));

        // dp[i][j] is no of wqys to reach [i][j] from [0][0]

        // dp[0][0] = 1;
        vector<int> prev(n, -1);
        prev[0] = 1;
        vector<int> cur(n, -1);
        cur[0] = 1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) {
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