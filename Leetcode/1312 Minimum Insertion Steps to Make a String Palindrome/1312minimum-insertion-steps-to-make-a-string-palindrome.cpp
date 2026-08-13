class Solution
{
public:
    int minInsertions(string s)
    {
        int n = s.length();
        // vector<vector<int>> dp(n, vector<int>(n, 0));
        // return solve(0, n - 1, dp, s);
        vector<int> prev(n, 0);
        int last;
        int diag = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            // prev[i] = 1;
            diag = 0;
            for (int j = i + 1; j < n; j++)
            {
                last = prev[j];
                if (s[i] == s[j])
                {
                    prev[j] = diag;
                }
                else
                {
                    int n1 = prev[j - 1];
                    // int n2 = dp[i + 1][j];
                    int n2 = prev[j];
                    prev[j] = 1 + min(n1, n2);
                }
                diag = last;
            }
        }
        return prev[n - 1];
    }
};