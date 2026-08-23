class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower,
                                               int upper) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;

        int last = lower - 1;

        for (int x : nums) {
            if (x < lower)
                continue;
            if (x > upper)
                break;

            if (x > last + 1) {
                ans.push_back({last + 1, x - 1});
            }

            last = x;
        }

        if (last < upper) {
            ans.push_back({last + 1, upper});
        }

        return ans;
    }
};