const int MOD = 1000000007;
class Solution
{
public:
    int dp[10001][6][10][10];
    // int solve(int i, int len, int a, int b, string &s)
    // {
    //     if (len == 5)
    //         return 1;
    //     if (i >= s.length())
    //         return 0;
    //     int x = s[i] - '0';

    //     if (dp[i][len][a][b] != -1)
    //         return dp[i][len][a][b];

    //     long long ans = solve(i + 1, len, a, b, s);
    //     if (len == 0)
    //         ans += solve(i + 1, 1, x, b, s);
    //     else if (len == 1)
    //         ans += solve(i + 1, 2, a, x, s);
    //     else if (len == 2)
    //         ans += solve(i + 1, 3, a, b, s);
    //     else if (len == 3)
    //     {
    //         if (x == b)
    //             ans += solve(i + 1, 4, a, b, s);
    //     }
    //     else if (len == 4)
    //     {
    //         if (x == a)
    //             ans += solve(i + 1, 5, a, b, s);
    //     }
    //     return ans % MOD;
    // }
    int countPalindromes(string s)
    {
        int n = s.size();
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i <= n; i++)
        {
            for (int a = 0; a < 10; a++)
            {
                for (int b = 0; b < 10; b++)
                {
                    dp[i][5][a][b] = 1;
                }
            }
        }
        for (int i = n - 1; i >= 0; i--)
        {
            for (int len = 0; len <= 4; len++)
            {
                for (int a = 0; a < 10; a++)
                {
                    for (int b = 0; b < 10; b++)
                    {

                        int x = s[i] - '0';

                        long long ans = dp[i + 1][len][a][b];
                        if (len == 0)
                            ans += dp[i + 1][1][x][b];
                        else if (len == 1)
                            ans += dp[i + 1][2][a][x];
                        else if (len == 2)
                            ans += dp[i + 1][3][a][b];
                        else if (len == 3)
                        {
                            if (x == b)
                                ans += dp[i + 1][4][a][b];
                        }
                        else if (len == 4)
                        {
                            if (x == a)
                                ans += dp[i + 1][5][a][b];
                        }
                        dp[i][len][a][b] = ans % MOD;
                    }
                }
            }
        }
        return dp[0][0][0][0];
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna