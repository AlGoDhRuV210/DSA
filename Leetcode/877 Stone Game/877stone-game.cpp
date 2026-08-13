// BOT KYA KAREGA MERA CODE DEKHKE , KHUD KARLE SOLVE PEHLE
// 😂
// 😂.😂😂😂😂😂😂😂😂😂😂
// 😂😂😂😂😂
// 😂          😂😂😂😂😂😂
// 😂.  😂 😂 😂 😂 😂
class Solution {
public:
    bool solve(int i, int j, vector<int>& nums, vector<vector<int>>& dp) {
        if (i == j)
            return nums[i];

        if (dp[i][j] != -1)
            return dp[i][j];

        int left = nums[i] - solve(i + 1, j, nums, dp);
        int right = nums[j] - solve(i, j - 1, nums, dp);

        return dp[i][j] = max(right, left);
    }
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        // vector<int> sum(n, 0);
        // sum[0] = piles[0];
        // for (int i = 1; i < n; i++) {
        //     sum[i] = sum[i - 1] + piles[i];
        // }
        // int total = accumulate(piles.begin(), piles.end(),0LL);
        vector<vector<int>> dp(n, vector<int>(n, -1));
        int maxi = solve(0, n - 1, piles, dp);
        return maxi >= 0;
        //    return solve(1, 0, n - 1, piles, 0, 0);
    }
};