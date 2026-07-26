class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int m = accumulate(nums.begin(), nums.end(), 0);
        if (m & 1)
            return false;
        int target = m / 2;
        // vector<vector<int>> dp(n, vector<int>(m + 1, -1));
        vector<bool> after(target + 1, -1);

        // solve(target, target, 0, nums, n, dp);
        for (int i = 0; i <= target; i++)
            after[i] = 0;
        after[0] = 1;
        if (nums[n - 1] <= target)
            after[nums[n - 1]] = 1;

        for (int i = n - 2; i >= 0; i--) {
            /* code */
            vector<bool> cur(target+1, -1);
            for (int sum = 0; sum <= target; sum++) {
                bool take = false;
                if (sum - nums[i] >= 0)
                    take = after[sum - nums[i]];

                bool nottake = after[sum];

                cur[sum] = take || nottake;
            }
            after = cur;
        }
        return after[target];
    }
};