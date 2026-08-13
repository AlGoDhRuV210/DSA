class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return nums[0];
 
        int prev2 = max(nums[0], nums[1]);
        if (n == 2)
            return prev2;
        int prev = max(prev2, nums[0] + nums[2]);

        for (int i = 3; i < n; i++) {
           int cur  = max(prev2 + nums[i], prev);
           prev2 = prev;
           prev = cur;
        }
        return  prev;
    }
};