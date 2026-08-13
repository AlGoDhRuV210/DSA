class Solution
{
public:
    bool solve(int chance, int i, int j, vector<int> &nums, int s1, int s2)
    {
        if (i > j)

            return s1 >= s2;
        if (chance == 1)
        {
            return solve(2, i + 1, j, nums, s1 + nums[i], s2) || solve(2, i, j - 1, nums, s1 + nums[j], s2);
        }
        return solve(1, i + 1, j, nums, s1, s2 + nums[i]) && solve(1, i, j - 1, nums, s1, s2 + nums[j]);
    }
    bool predictTheWinner(vector<int> &nums)
    {
        int n = nums.size();

        return solve(1, 0, n - 1, nums, 0, 0);
    }
};