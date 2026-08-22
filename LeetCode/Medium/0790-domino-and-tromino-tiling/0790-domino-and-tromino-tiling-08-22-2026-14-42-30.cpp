#define mod 1000000007
class Solution
{
public:
    int solve(int i, int j)
    {
        if (i <= 0)
            return 1;
        if (dp[i][j] != -1)
            return dp[i][j];
        int ans = 0;
        if (j == 0)
        {
            ans += solve(i - 1, 0);
            if (i > 1)
                ans += solve(i - 2, 0);
            ans = ans % mod;
            if (i > 2)
            {
                ans += 2 * solve(i - 2, 1) % mod;
                ans = ans % mod;
            }
        }
        else
        {
            ans += solve(i - 1, 0);
            ans = ans % mod;
            if (i > 1)
                ans += solve(i - 1, 1);
            ans = ans % mod;
        }
        ans = ans % mod;

        return dp[i][j] = ans;
    }
    vector<vector<int>> dp;
    int numTilings(int n)
    {

        dp.assign(n + 1, (vector<int>(2, -1)));
        return solve(n, 0);
    }
};