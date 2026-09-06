class Solution
{
public:
    int numDistinct(string s, string t)
    {
        int n1 = s.length();
        int n2 = t.length();
        vector<vector<unsigned int>> dp(n2, vector<unsigned int>(n1, 0));
        if (s[0] == t[0])
            dp[0][0] = 1;
        for (int i = 1; i < n1; i++)
        {
            /* code */
            dp[0][i] = ((s[i] == t[0]) ? dp[0][i - 1] + 1 : dp[0][i - 1]);
        }
        // for (int i = 1; i < n2; i++)
        // {
        //     /* code */
        //     dp[i][0] = ((t[i] == s[0]) ? dp[i - 1][0] + 1 : dp[i - 1][0]);
        // }
        for (int i = 1; i < n2; i++)
        {
            /* code */
            char c = t[i];
            for (int j = 1; j < n1; j++)
            {

                if (c == s[j])
                    dp[i][j] = dp[i - 1][j-1] + dp[i][j - 1];
                else
                    dp[i][j] = dp[i][j - 1];
            }
        }
        return dp[n2 - 1][n1 - 1];
    }
};