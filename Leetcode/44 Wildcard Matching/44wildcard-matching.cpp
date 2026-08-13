class Solution {
public:
    bool isMatch(string s, string p) {
        int n1 = s.length();
        int n2 = p.length();

        // vector<vector<int>> dp(n1 + 1, (vector<int>(n2 + 1, 0)));
        vector<int> prev(n2 + 1, 0);
        //  cur(n2 + 1, 0);
        prev[0] = true;

        for (int j = 1; j <= n2; j++) {
            if (p[j - 1] == '*')
                prev[j] = prev[j - 1];
            else
                prev[j] = false;
        }

        // for (int i = 1; i <= n1; i++)
        //    prev[0] = false;
        int diag;
        for (int i = 1; i <= n1; i++) {
            /* code */
            int diag = prev[0]; // old dp[i-1][0]
            prev[0] = false;    // dp[i][0]
            for (int j = 1; j <= n2; j++) {
                int temp = prev[j];
                if (s[i - 1] == p[j - 1] || p[j - 1] == '?')
                    prev[j] = diag;
                else {
                    if (p[j - 1] == '*')
                        prev[j] = prev[j] || prev[j - 1];
                    else
                        prev[j] = false;
                }

                diag = temp;
            }
            // prev = cur;
        }

        return prev[n2];
    }
};