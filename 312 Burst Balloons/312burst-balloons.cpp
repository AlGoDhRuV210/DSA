class Solution
{
public:
    int solve(int i, int j, vector<vector<int>> &dp, vector<int> &nums)
    {
        if (i > j)
            return 0;
        if (i == j)
            return nums[i] * nums[i - 1] * nums[i + 1];

        if (dp[i][j] != -1)
            return dp[i][j];
        int cur = 0;
        for (int k = i; k <= j; k++)
        {
            int coins = nums[k] * nums[i - 1] * nums[j + 1] +
                        solve(i, k - 1, dp, nums) + solve(k + 1, j, dp, nums);
            cur = max(cur, coins);
        }
        return dp[i][j] = cur;
    }
    int maxCoins(vector<int> &nums)
    {
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(n+1,0));

        for (int i = n - 1; i >= 1; i--)
        {
            /* code */
            for (int j = i; j < n-1; j++)
            {
                int cur = 0;
                for (int k = i; k <= j; k++)
                {
                    int coins = nums[k] * nums[i - 1] * nums[j + 1] +
                                dp[i][k - 1] + dp[k + 1][j];
                    cur = max(cur, coins);
                }
                 dp[i][j] = cur;
            }
        }

        return dp[1][n - 2];
    }
};