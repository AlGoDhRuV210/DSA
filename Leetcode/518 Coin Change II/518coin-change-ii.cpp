class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<unsigned int>> dp(n, vector<unsigned int>(amount + 1, 0));

        // solve(n - 1, amount, coins, dp);
        // return dp[n - 1][amount] >= 1e8 ? -1 : dp[n - 1][amount];

        for (int i = 0; i <= amount; i++) {
            if (i % coins[0] == 0)
                dp[0][i] = 1;
            else
                dp[0][i] = 0;
        }

        if (coins[0] == 0)
            dp[0][0] = 2;
        for (int i = 0; i < n; i++)
            dp[i][0] = 1;

        for (int i = 1; i < n; i++) {
            for (int cur = 0; cur <= amount; cur++) {
                long long take = 0;
                if (coins[i] <= cur)
                    take = dp[i][cur - coins[i]];
                long long nottake = dp[i - 1][cur];
                // if (take <= -1)
                //     take = 0;
                // if (nottake <= -1)
                //     nottake = 0;
                dp[i][cur] = take + nottake;
            }
        }
        return dp[n - 1][amount];
    }
};