class Solution
{
public:
    // int solve(int i, vector<int> &dp, vector<int> &nums)
    // {
    //     if (i == 0)
    //         return 1;

    //     if (dp[i] != -1)
    //         return dp[i];
    //     int ans = 1;
    //     for (int j = i - 1; j >= 0; j--)
    //     {
    //         if (nums[j] < nums[i])
    //             ans = max(ans, solve(j, dp, nums) + 1);
    //     }

    //     return dp[i] = ans;
    // }
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();

        vector<int> dp(n, -1);
        dp[0] = 1;
        int ans = 1;
        for (int i = 0; i < n; i++)
        {
            int cur = 1;
            for (int j = i - 1; j >= 0; j--)
            {
                if (nums[j] < nums[i])
                    cur = max(cur, dp[j] + 1);
            }
            ans = max(ans, cur);
            dp[i] = cur;
        }

        return ans;
    }
};