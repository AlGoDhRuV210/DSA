class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        int ans1, ans2;
        int z = 1;
        if(n==3)
        {
            return max({nums[0],nums[1],nums[2]});
        }
        while (z--)
        {
            if (n == 1)
            {
                ans1 = nums[0];
                break;
            }

            int prev2 = max(nums[0], nums[1]);
            if (n == 2)
            {
                ans1 = prev2;
                break;
            }
            int prev = max(prev2, nums[0] + nums[2]);

            for (int i = 3; i < n - 1; i++)
            {
                int cur = max(prev2 + nums[i], prev);
                prev2 = prev;
                prev = cur;
            }
            ans1 = prev;
        }
        z = 1;
        while (z--)

        {
            // exclude nums[0] and take start from i = 1
            if (n == 1)
            {
                ans2 = nums[0];
                break;
            }

            int prev2 = nums[1];
            if (n == 2)
            {
                ans2 = max(nums[0], nums[1]);
                break;
            }
            int prev = max(prev2, nums[2]);

            for (int i = 3; i < n; i++)
            {
                int cur = max(prev2 + nums[i], prev);
                prev2 = prev;
                prev = cur;
            }
            ans2 = prev;
        }
        return max(ans2, ans1);
    }
};