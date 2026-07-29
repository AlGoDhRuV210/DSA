class Solution {
public:
    // int solve(int i, int j, vector<vector<int>>& dp, string& text1,
    //           string& text2) {
    //     int n1 = text1.size();
    //     int n2 = text2.size();

    //     if (i == 0)
    //         return text2.find(text1[i]) != string::npos &&
    //                text2.find(text1[i]) <= j;
    //     if (j == 0)
    //         return text1.find(text2[j]) != string::npos &&
    //                text1.find(text2[j]) <= i;

    //     if (dp[i][j] != -1)
    //         return dp[i][j];

    //     int ans = 0;
    //     if (text1[i] == text2[j])
    //         ans = max(ans, 1 + solve(i - 1, j - 1, dp, text1, text2));

    //     ans = max(ans, solve(i, j - 1, dp, text1, text2));
    //     ans = max(ans, solve(i - 1, j, dp, text1, text2));

    //     return dp[i][j] = ans;
    // }
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size();
        int n2 = text2.size();
        vector<vector<int>> dp(n1, vector<int>(n2, -1));

        for (int i = 0; i < n2; i++) {
            dp[0][i] = (text2.find(text1[0]) != string::npos &&
                        text2.find(text1[0]) <= i);
        }

        for (int i = 0; i < n1; i++) {
            dp[i][0] = (text1.find(text2[0]) != string::npos &&
                        text1.find(text2[0]) <= i);
        }

        for (int i = 1; i < n1; i++) {
            for (int j = 1; j < n2; j++) {
                int ans = 0;
                if (text1[i] == text2[j])
                    ans = max(ans, 1 +dp[i-1][j-1]);

                ans = max(ans, dp[i][j-1]);
                ans = max(ans, dp[i-1][j]);

                 dp[i][j] = ans;
            }
        }

        return dp[n1 - 1][n2 - 1];
    }
};