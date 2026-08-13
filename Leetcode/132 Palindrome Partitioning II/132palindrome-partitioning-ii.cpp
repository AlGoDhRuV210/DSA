class Solution {
public:
    int solve(int i, vector<int> &dp, string& s,
              vector<vector<int>>& palindrome) {
        int n = s.length();
        if (i >= n)
            return 0;

        if (dp[i] != -1)
            return dp[i];
        int ways = INT_MAX;
        for (int k = i; k < n; k++) {
            if (palindrome[i][k])
                ways = min(ways, 1+ solve(k+1, dp, s, palindrome));
        }

        return dp[i] = ways;
    }
    int minCut(string s) {
        int n = s.length();
        if (n == 1)
            return 0;
        string temp = s;
        reverse(temp.begin(), temp.end());
        if (temp == s)
            return 0;

        vector<vector<int>> palindrome(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
            palindrome[i][i] = 1;
        for (int i = 0; i < n; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (j == i - 1) {
                    if (s[j] == s[i])
                        palindrome[j][i] = 1;
                    continue;
                }
                palindrome[j][i] =
                    (s[i] == s[j] && palindrome[j + 1][i - 1] == 1 ? 1 : 0);
            }
        }

        vector<int> dp(n, -1)  ;

        return solve(0, dp, s, palindrome) -1;
    }
};