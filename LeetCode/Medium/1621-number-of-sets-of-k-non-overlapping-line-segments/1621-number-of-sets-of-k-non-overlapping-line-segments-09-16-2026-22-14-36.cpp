class Solution {
public:
    int mod = 1000000007;
    int numberOfSets(int n, int k) {
        if (n == k - 1)
            return 1;

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for (int i = 0; i <= n; i++)
            dp[i][0] = 1;

        for (int j = 1; j <= k; j++) {
            long long sum = 0;

            for (int i = 1; i <= n; i++) {


                if (i - 1 >= 1)
                    sum = (sum + dp[i - 1][j - 1]) % mod;

                dp[i][j] = (dp[i - 1][j] + sum) % mod;
            }
        }
        return dp[n][k];
    }
};
