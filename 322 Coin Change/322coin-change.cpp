class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        sort(coins.begin(), coins.end());
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));

        // solve(n - 1, amount, coins, dp);
        // return dp[n - 1][amount] >= 1e8 ? -1 : dp[n - 1][amount];

        for (int i = 0; i <= amount; i++) {
            if (i % coins[0] == 0)
                dp[0][i] = i / coins[0];
            else
                dp[0][i] = 1e8;
        }

        for (int i = 1; i < n; i++) {
            for (int cur = 0; cur <= amount; cur++) {
                int ans = 0;
                int take = 1e8;
                if (coins[i] <= cur)
                    take = 1 + dp[i][cur - coins[i]];
                int nottake = dp[i - 1][cur];

                dp[i][cur] = min(nottake, take);
            }
        }
        return dp[n - 1][amount]>=1e8 ? -1 : dp[n-1][amount];
    }
};