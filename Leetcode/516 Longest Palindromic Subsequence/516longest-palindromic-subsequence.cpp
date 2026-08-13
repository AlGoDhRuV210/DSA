class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        // vector<vector<int>>    dp(n, vector<int>(n, 0));
        vector<int> prev(n, 0);
        // vector<int> cur(n, 0);
        // for (int i = 0; i < n; i++)
        // {
        //     /* code */
        //     dp[i][i] = 1;
        // }
        int last;
        for (int i = n - 1; i >= 0; i--) {
            int diag = 0;
            prev[i] = 1;
            for (int j = i + 1; j < n; j++) {
                last = prev[j];
                if (s[i] == s[j]) {
                    prev[j] = 2 + diag;
                } else {
                    int n1 = prev[j - 1];
                    int n2 = prev[j];
                    prev[j] = max(n1, n2);
                }
                diag = last;
            }
        }
        return prev[n - 1];
    }
};