class Solution {
public:
    int solve(int i, vector<long long>& dp, vector<int>& arr, int k) {
        int n = arr.size();
        if (i >= n)
            return 0;

        if (dp[i] != -1)
            return dp[i];

        long long ans = 0;
        int maxele = 0;
        for (int j = i; j < i + k && j < n; j++) {
            maxele = max(maxele, arr[j]);
            long long cur = maxele * (j - i + 1) + solve(j + 1, dp, arr, k);
            ans = max(ans, cur);
        }

        return dp[i] = ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<long long> dp(n, 0);

        for (int i = n - 1; i >= 0; i--) {
            long long ans = 0;
            int maxele = 0;
            for (int j = i; j < i + k && j < n; j++) {
                maxele = max(maxele, arr[j]);
                long long cur = maxele * (j - i + 1) + solve(j + 1, dp, arr, k);
                ans = max(ans, cur);
            }

             dp[i] = ans;
        }
        return dp[0];
    }
};