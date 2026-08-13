class Solution
{
public:
    int maxProfit(vector<int> &prices, int fee)
    {

        {
            int n = prices.size();

            vector<vector<int>> dp(n + 1, vector<int>(2, 0));
            // dp[index][buy][no of trades left]

            for (int i = n - 1; i >= 0; i--)
            {
                /* code */
                dp[i][1] = max(dp[i + 1][1], -prices[i]- fee + dp[i + 1][0]);
                int m = i + 1 <= n + 1 ? dp[i + 1][1] : 0;
                dp[i][0] = max(dp[i + 1][0], prices[i] + m );
            }

            return dp[0][1];
        }
    }
};