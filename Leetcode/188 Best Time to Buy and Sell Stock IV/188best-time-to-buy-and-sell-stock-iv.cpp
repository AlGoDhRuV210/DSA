class Solution
{
public:
    int solve(int i, int buy, int trans, vector<vector<vector<int>>> &dp, vector<int> &prices)
    {
        int n = prices.size();
        if (i == n || trans == 0)
            return 0;

        if (dp[i][buy][trans] != -1)
            return dp[i][buy][trans];

        if (buy)
        {
            return dp[i][buy][trans] = max(solve(i+1,buy,trans,dp,prices),-prices[i]+solve(i+1,0,trans,dp,prices));
        }
        else
        {
            return dp[i][buy][trans] = max(solve(i+1,buy,trans,dp,prices),prices[i]+solve(i+1,1,trans-1,dp,prices));
        }
    }
    int maxProfit(int k ,vector<int> &prices)
    {
        int n = prices.size();

        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(2, vector<int>(k+1, -1)));
        // dp[index][buy][no of trades left]

        return solve(0, 1, k, dp, prices);
    }
};