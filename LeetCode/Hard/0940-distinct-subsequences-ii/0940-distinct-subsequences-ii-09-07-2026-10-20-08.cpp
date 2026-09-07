class Solution {
public:
    int distinctSubseqII(string s) {
        int n = s.size();
        vector<int> last(26, -1);
        // vector<int> dp(n + 1, 0);
        int mod = (int)(1e9) + 7;
        int ll = 1;
        int cur;
        vector<int> l(26, 0);
        vector<int> prev0fl(26, 0);

        // dp[0] = 1;
        for (int i = 0; i < n; i++) {
            // dp[i + 1] = (dp[i] * 2) % mod;
            // if (last[s[i] - 'a'] != -1)
            //     dp[i + 1] -= dp[last[s[i]-'a']];
            // dp[i + 1] %= mod;

            // last[s[i] - 'a'] = i;

            cur = (ll * 2LL )% mod;
            cur%=mod;
            if (last[s[i] - 'a'] != -1)
                cur -= prev0fl[s[i]-'a'];
                cur%=mod;

            last[s[i] - 'a'] = i;

            l[s[i]-'a']=cur;
            prev0fl[s[i]-'a']=ll;
            ll = cur;
        }

        ll--;
        if (ll < 0)
            ll += mod;
        return ll;
    }
};