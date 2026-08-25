class Solution
{
public:
    int missingMultiple(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        int t = k;
        while (1)
        {
            if (!binary_search(nums.begin(), nums.end(), k))
                return k;
            k += t;
        }
        return -1;
    }
};