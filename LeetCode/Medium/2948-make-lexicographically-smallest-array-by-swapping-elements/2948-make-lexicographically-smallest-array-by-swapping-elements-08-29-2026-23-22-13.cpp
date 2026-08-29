class Solution
{
public:
    vector<int> lexicographicallySmallestArray(vector<int> &nums, int limit)
    {
        int n = nums.size();

        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());

        vector<vector<int>> grp;
        grp.push_back({sorted[0]});

        for (int i = 1; i < n; i++)
        {
            if (sorted[i] - sorted[i - 1] > limit)
            {
                grp.push_back({});
            }

            grp.back().push_back(sorted[i]);
        }

        unordered_map<int, int> mpp;

        for (int g = 0; g < grp.size(); g++)
        {
            for (int x : grp[g])
            {
                mpp[x] = g;
            }
        }

        vector<int> index(grp.size(), 0);

        for (int i = 0; i < n; i++)
        {
            int x = nums[i];
            int g = mpp[x];

            nums[i] = grp[g][index[g]];
            index[g]++;
        }

        return nums;
    }
};