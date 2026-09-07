class Solution {
public:
    int distinctSubseqII(string s) {
        int n = s.size();
        vector<int> last(26, -1);
         vector<int> dp(n + 1, 0);
        int mod = (int)(1e9) + 7;
        dp[0]=1;
        for (int i = 0; i < n; i++) {
            dp[i + 1] = (dp[i] * 2) % mod;
            if (last[s[i] - 'a'] != -1)
                dp[i + 1] -= dp[last[s[i]-'a']];
            dp[i + 1] %= mod;

            last[s[i] - 'a'] = i;
        }

        dp[n]--;
        if (dp[n] < 0)
            dp[n] += mod;
        return dp[n];
    }
};