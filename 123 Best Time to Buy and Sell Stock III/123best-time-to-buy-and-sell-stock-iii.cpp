class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();

        // vector<vector<vector<long long>>> dp(
        // n + 1, vector<vector<long long>>(2, vector<long long>(3, 0)));
        // dp[index][buy][no of trades left]
        vector<vector<int>> prev(2, (vector<int>(3, 0)));
        vector<vector<int>> cur(2, (vector<int>(3, 0)));
        for (int i = n - 1; i >= 0; i--)
        {
            /* code */
            // cur[0][0]=0;
            // cur[1][0]=0;
            for (int buy = 0; buy <= 1; buy++)
            {
                for (int trans = 1; trans <= 2; trans++)
                {
                    if (buy)
                    {
                        cur[buy][trans] =
                            max(prev[buy][trans],
                                -prices[i] + prev[0][trans]);
                    }
                    else

                    {
                        cur[buy][trans] =
                            max(prev[buy][trans],
                                prices[i] + prev[1][trans - 1]);
                    }
                }
            }
                prev = cur;
        }

        return prev[1][2];
    }
};