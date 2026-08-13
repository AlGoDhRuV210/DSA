class Solution {
public:
    vector<int> prev;

    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();

        prev.assign(n, -1);
        sort(nums.begin(), nums.end());
        vector<int> dp(n, 0);
        vector<int> ans;

        for (int i = 0; i < n; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (nums[i] % nums[j] == 0) {
                    if (dp[j] + 1 > dp[i]) {
                        dp[i] = 1 + dp[j];
                        prev[i] = j;
                    }
                }
            }
        }

        int maxLen = 0, maxIndex = 0;
        for (int i = 0; i < n; i++) {
            if (dp[i] > maxLen) {
                maxLen = dp[i];
                maxIndex = i;
            }
        }
        int curr = maxIndex;
        while (curr != -1) {
            ans.push_back(nums[curr]);
            curr = prev[curr];
        }

        return ans;
    }
};