class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<int> ss(n, 1);
        vector<int> dp(n, 1);
        dp[0] = 1;
        ss[0] = 1;
        int maxlen = 1;
        for (int i = 1; i < n; i++) {
            int cur = 1;
            for (int j = 0; j <i; j++) {
                if (nums[j] < nums[i] && cur < dp[j] + 1) {
                    cur = dp[j] + 1;
                    ss[i] = ss[j];
                } else if (nums[j] < nums[i] && cur == dp[j] + 1)
                    ss[i]+=ss[j];
            }
            dp[i] = cur;
            maxlen = max(maxlen, dp[i]);
        }
        int x = 0;
        for (int i = 0; i < n; i++) {
            if (dp[i] == maxlen)
                x += ss[i];
        }
        return x;
    }
    int findNumberOfLIS(vector<int>& nums) {
        return lengthOfLIS(nums);
    }
};