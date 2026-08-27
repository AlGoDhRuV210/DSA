class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        int n = nums.size();
        int total = accumulate(nums.begin(), nums.end(), 0LL);
        int x = total / 2;
        int cur = 0;
        vector<int> ans;
        sort(nums.begin(), nums.end());
        int i = n - 1;
        while (cur <= x) {
            cur += nums[i];
            ans.push_back(nums[i]);
            i--;
        }

        return ans;
    }
};