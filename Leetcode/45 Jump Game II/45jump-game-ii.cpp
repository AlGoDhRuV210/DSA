class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int jumps = 0;
        int last = 0;
        int n = nums.size();
        int mxreachable = 0;
        for (int i = 0; i < nums.size() && last<n-1; i++)
        {
            mxreachable = max(mxreachable, nums[i] + i);
            if (i == last)
            {
                jumps++;
                last = mxreachable;
            }
        }

        return jumps;
    }
};