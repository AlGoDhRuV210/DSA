class Solution {
public:
    bool is_palindrome(int i, int j, string& s) {
        string t = s;
        reverse(t.begin(), t.end());
        return t == s;
    }

    int maxPalindromes(string s, int k) {

        int n = s.size();
        if (k == 1)
            return n;
        vector<vector<bool>> v(n + 1, vector<bool>(n + 1, false));

        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {

                if (s[i] == s[j] && (j - i <= 2 || v[i + 1][j - 1])) {
                    v[i][j] = true;
                }
            }
        }
        vector<int> dp(n, 0);
        for (int i = k - 1; i < n; i++) {
            if (i > 0)
                dp[i] = dp[i - 1];
            for (int j = i - 1; j >= 0; j--) {
                if (s[i] != s[j] || (!v[j][i]) || i - j + 1 < k)
                    continue;
                int b = 0;
                if (j > 0)
                    b = dp[j - 1];
                dp[i] = max(dp[i], 1 + b);
            }
        }

        return dp[n - 1];
    }
};