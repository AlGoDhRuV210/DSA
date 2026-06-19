class Solution
{
public:
    int numSubarraysWithSum(vector<int> &nums, int goal)
    {
        int l = 0;
        int cur = 0;
        int ans = 0;
        int m;
        for (int r = 0; r < nums.size(); r++)
        {
            cur += nums[r];
            if (cur == goal)
            {
                ans++;
                m = l;
                while (nums[m] == 0 && m < r)
                {
                    ans++;
                    m++;
                }
            }
            else if (cur > goal)
            {
                while (cur > goal && l<r)
                {
                    cur -= nums[l];
                    l++;
                }
                if(cur==goal)
                {ans++;
                m = l;
                while (nums[m] == 0 && m < r)
                {
                    ans++;
                    m++;
                }}
            }
        }
        return ans;
    }
};