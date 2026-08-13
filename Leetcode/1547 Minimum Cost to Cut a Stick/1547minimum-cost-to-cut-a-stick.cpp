class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        int m = cuts.size();
        sort(cuts.begin(), cuts.end());

        vector<vector<int>> dp(m, vector<int>(m, 0));

        for (int i = m - 1; i >= 0; i--) {
            for (int j = i + 2; j < m; j++) {
                int cur = INT_MAX;
                for (int k = i + 1; k < j; k++) {
                    cur = min(cur, dp[i][k] + dp[k][j] + cuts[j] - cuts[i]);
                }
                dp[i][j] = cur;
            }
        }

        return dp[0][m - 1];
    }
};