class Solution {
public:
    vector<int> prefix;
    vector<vector<int>> dp;
    int solve(int i, int j, vector<int>& a) {

        if (i >= j)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];
        int sum = INT_MIN;
        for (int k = i; k < j; k++) {
            int b = 0;
            if (i > 0)
                b = prefix[i - 1];
            int l = prefix[k] - b;
            int r = prefix[j] - prefix[k];
            if (l > r) {
                sum = max(sum, r + solve(k + 1, j, a));
            } else if (r > l) {

                sum = max(sum, l + solve(i, k, a));
            } else {
                sum = max(sum, r + solve(k + 1, j, a));
                sum = max(sum, l + solve(i, k, a));
            }
        }
        return dp[i][j] = sum;
    }
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        if (n == 1)
            return 0;
        prefix.assign(n, 0);
        prefix[0] = stoneValue[0];
        for (int i = 1; i < n; i++)
            prefix[i] = prefix[i - 1] + stoneValue[i];
        dp.assign(n, vector<int>(n, -1));

        return solve(0, n - 1, stoneValue);
    }
};