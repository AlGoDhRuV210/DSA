class Solution {
public:
    int distinctSubseqII(string s) {
        int n = s.size();
        vector<int> last(26, -1);
        // vector<int> dp(n + 1, 0);
        int mod = (int)(1e9) + 7;
        int ll = 1;
        int cur;

        vector<int> prev0fl(26, -1);
        for (int i = 0; i < n; i++) {

            cur = (ll * 2LL) % mod;
            cur %= mod;
            if (last[s[i] - 'a'] != -1)
                cur -= prev0fl[s[i] - 'a'];
            cur %= mod;

            last[s[i] - 'a'] = i;

            prev0fl[s[i] - 'a'] = ll;
            ll = cur;
        }

        ll--;
        if (ll < 0)
            ll += mod;
        return ll;
    }
};