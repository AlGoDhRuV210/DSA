class Solution {
public:
    int mod = 1000000007;
    int numberOfSets(int n, int k) {
        if (n == k - 1)
            return 1;

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for (int i = 0; i <= n; i++)
            dp[i][0] = 1;

        vector<long long> pref(k + 1, 0);

        for (int i = 1; i <= n; i++) {

            if (i >= 2) {
                for (int j = 1; j <= k; j++) {
                    pref[j] = (pref[j] + dp[i - 1][j - 1]) % mod;
                }
            }

            for (int j = 1; j <= k; j++) {
                dp[i][j] = (dp[i - 1][j] + pref[j]) % mod;
            }
        }

        return dp[n][k];
    }
};
