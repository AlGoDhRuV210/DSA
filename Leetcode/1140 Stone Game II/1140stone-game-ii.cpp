class Solution {
public:
    int solve(int i, int m, vector<vector<int>>& dp, vector<int>& piles,
              vector<int>& prefix) {
        int n = piles.size();
        if (i >= n)
            return 0;
        if (i == n - 1)
            return piles[i];

        if (dp[i][m] != -1)
            return dp[i][m];

        int ans = 0;

        for (int x = 1; x <= 2 * m; x++) {
            if (i + x > n)
                break;
            int cur = prefix[i + x - 1] - prefix[i] + piles[i];
            cur += (prefix[n - 1] - prefix[i + x - 1] -
                    solve(i + x, max(m, x), dp, piles, prefix));

            ans = max(ans, cur);
        }
        return dp[i][m] = ans;
    }
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<int> prefix(n, 0);

        prefix[0] = piles[0];
        for (int i = 1; i < n; i++)
            prefix[i] = piles[i] + prefix[i - 1];

        vector<vector<int>> dp(n, vector<int>(n, -1));

        return solve(0, 1, dp, piles, prefix);
    }
};