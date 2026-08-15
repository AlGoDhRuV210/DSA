class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        long long x = 0;
        int n = nums.size();
        for (auto i : nums)
            x = x ^ i;
        if (x != 0)
            return n;
        for (auto i : nums) {
            if (x ^ i != 0)
                return n - 1;
        }
        return 0;
    }
};