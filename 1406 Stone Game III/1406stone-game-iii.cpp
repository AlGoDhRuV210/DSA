class Solution {
public:
    // int solve(int i, vector<int> &dp, vector<int> &nums)
    // {
    //     int n = nums.size();
    //     if (i == n)
    //         return 0;
    //     if (i == n - 1)
    //         return nums[i];
    //     if (i == n - 2)
    //         return max(nums[i] + nums[i + 1], nums[i] - nums[i + 1]);

    //     if (dp[i] != -1e9)
    //         return dp[i];

    //     int pick1 = nums[i] - solve(i + 1, dp, nums);
    //     int pick2 = nums[i] + nums[i + 1] - solve(i + 2, dp, nums);
    //     int pick3 =
    //         nums[i] + nums[i + 1] + nums[i + 2] - solve(i + 3, dp, nums);

    //     return dp[i] = max({pick1, pick2, pick3});
    // }
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        // vector < long long total =
        //     accumulate(stoneValue.begin(), stoneValue.end(), 0LL);
        string ans;
        if (n == 1) {
            int ele = stoneValue[0];
            if (ele > 0)
                return "Alice";
            if (ele == 0)
                return "Tie";

            return "Bob";
        }
        vector<int> dp(n + 1, 0);
        dp[n - 1] = stoneValue[n - 1];
        dp[n - 2] = max(stoneValue[n - 2] + stoneValue[n - 1],
                        stoneValue[n - 2] - stoneValue[n - 1]);
        for (int i = n - 3; i >= 0; i--) {
            int pick1 = stoneValue[i] - dp[i + 1];
            int pick2 = stoneValue[i] + stoneValue[i + 1] - dp[i + 2];
            int pick3 = stoneValue[i] + stoneValue[i + 1] + stoneValue[i + 2] -
                        dp[i + 3];

            dp[i] = max({pick1, pick2, pick3});
        }

        int maxi = dp[0];

        if (maxi > 0)
            ans = "Alice";
        else if (maxi == 0)
            ans = "Tie";
        else
            ans = "Bob";

        return ans;
    }
};