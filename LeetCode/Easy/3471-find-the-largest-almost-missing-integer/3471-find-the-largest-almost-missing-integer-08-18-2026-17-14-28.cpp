class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> mpp(51,0);
        for (auto i : nums)
            mpp[i]++;
        if (k == 1) {
            int ans = -1;
            for(int i = 0;i<51;i++) {
                if (mpp[i] == 1)
                    ans = max(ans, i);
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