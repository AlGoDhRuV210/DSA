class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        map<int, int> mpp;
        int n = nums.size();
        for (auto i : nums)
            mpp[i]++;
        if (k == 1) {
            int ans = -1;
            for (auto i : mpp) {
                if (i.second == 1)
                    ans = max(ans, i.first);
            }
            return ans;
        }
        if (k == n)
            return *max_element(nums.begin(), nums.end());

        int ans = -1;
        if (mpp[nums[0]] == 1)
            ans = max(ans, nums[0]);
        if (mpp[nums[n - 1]] == 1)
            ans = max(ans, nums[n - 1]);
        return ans;
    }
};